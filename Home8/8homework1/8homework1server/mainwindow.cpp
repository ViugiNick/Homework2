#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    tcpServer(0),
    clientSocket(0),
    networkSession(0),
    blockSize(0)
{
    ui->setupUi(this);
    ui->textEdit->setReadOnly(true);
    ui->messageLine->setEnabled(false);
    disableSmiles();

    connect(ui->smileButton1, SIGNAL(clicked()), this, SLOT(addSmile1()));
    connect(ui->smileButton2, SIGNAL(clicked()), this, SLOT(addSmile2()));
    connect(ui->smileButton3, SIGNAL(clicked()), this, SLOT(addSmile3()));

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) != QNetworkConfiguration::Discovered)
        {
            config = manager.defaultConfiguration();
        }

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        ui->statusLabel->setText("Opening network session.");
        networkSession->open();
    }
    else
        sessionOpened();

    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(tcpServer, SIGNAL(newConnection()), this, SLOT(acceptConnection()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sessionOpened()
 {
     if (networkSession)
     {
         QNetworkConfiguration config = networkSession->configuration();
         QString id;
         if (config.type() == QNetworkConfiguration::UserChoice)
             id = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
         else
             id = config.identifier();
     }

     tcpServer = new QTcpServer(this);
     if (!tcpServer->listen(QHostAddress::LocalHost, tcpServer->serverPort()))
     {
         QMessageBox::critical(this, "Server",
                               "Unable to start the server: " + tcpServer->errorString());
         close();
         return;
     }

     ui->statusLabel->setText(tr("The server is running on\n\nIP: %1\nport: %2\n\n")
                          .arg(tcpServer->serverAddress().toString()).arg(tcpServer->serverPort()));
 }

void MainWindow::acceptConnection()
{
    clientSocket = tcpServer->nextPendingConnection();
    ui->sendButton->setEnabled(true);
    ui->messageLine->setEnabled(true);
    enableSmiles();
    connect(clientSocket, SIGNAL(readyRead()), this, SLOT(startReading()));
    connect(clientSocket, SIGNAL(disconnected()), this, SLOT(clientDisconnected()));
    connect(clientSocket, SIGNAL(disconnected()), clientSocket, SLOT(deleteLater()));
}

void MainWindow::enableSmiles()
{
    ui->smileButton1->setEnabled(true);
    ui->smileButton2->setEnabled(true);
    ui->smileButton3->setEnabled(true);
}

void MainWindow::disableSmiles()
{
    ui->smileButton1->setEnabled(false);
    ui->smileButton2->setEnabled(false);
    ui->smileButton3->setEnabled(false);
}
void MainWindow::addSmile1()
{
    ui->messageLine->setText(ui->messageLine->text() + ui->smileButton1->text());
}

void MainWindow::addSmile2()
{
    ui->messageLine->setText(ui->messageLine->text() + ui->smileButton2->text());
}

void MainWindow::addSmile3()
{
    ui->messageLine->setText(ui->messageLine->text() + ui->smileButton3->text());
}

void MainWindow::startReading()
{
    QDataStream in(clientSocket);
    in.setVersion(QDataStream::Qt_5_1);

    if (blockSize == 0)
    {
        if (clientSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;
    }

    if (clientSocket->bytesAvailable() < blockSize)
             return;

    blockSize = 0;
    QString newMessage;
    in >> newMessage;
    ui->textEdit->textCursor().insertText("client: " + newMessage + '\n');
}

void MainWindow::sendMessage()
{
    if(clientSocket)
    {
        QString tmp = ui->messageLine->text();
        if (!isNotSpaces(tmp))
            return;

        ui->sendButton->setEnabled(false);
        QByteArray block;
        QDataStream out(&block, QIODevice::WriteOnly);
        ui->messageLine->clear();
        out << (quint16)tmp.length();
        out << tmp;
        clientSocket->write(block);
        ui->textEdit->textCursor().insertText("you: " + tmp + '\n');
        ui->sendButton->setEnabled(true);
    }
}

void MainWindow::clientDisconnected()
{
    ui->sendButton->setEnabled(false);
    ui->messageLine->setEnabled(false);
    disableSmiles();
    QMessageBox::warning(this, "Warning!", "Client disconnected");
}


bool MainWindow::isNotSpaces(QString qStr)
{
    int length = qStr.length();
    for (int i = 0; i < length; ++i)
        if (qStr.at(i) != ' ')
            return true;

    return false;
}
