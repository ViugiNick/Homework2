#include <QLayout>
#include <QMessageBox>
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    networkSession(0),
    blockSize(0)
{
    ui->setupUi(this);
    ui->hostBox->setEditable(true);
    ui->quitButton->setAutoDefault(false);
    ui->sendButton->setEnabled(false);
    ui->textEdit->setReadOnly(true);
    ui->messageLine->setEnabled(false);
    disableSmiles();

    connect(ui->smileButton1, SIGNAL(clicked()), this, SLOT(addSmile1()));
    connect(ui->smileButton2, SIGNAL(clicked()), this, SLOT(addSmile2()));
    connect(ui->smileButton3, SIGNAL(clicked()), this, SLOT(addSmile3()));

    ui->portLine->setValidator(new QIntValidator(1, 65535, this));

    QString nameOfYourPC = QHostInfo::localHostName();

    if (nameOfYourPC != "localhost")
        ui->hostBox->addItem("localhost");

    if (!nameOfYourPC.isEmpty())
    {
        ui->hostBox->addItem(nameOfYourPC);
        QString domain = QHostInfo::localDomainName();
        if (!domain.isEmpty())
            ui->hostBox->addItem(nameOfYourPC + QChar('.') + domain);
    }

    QList<QHostAddress> ipAddressesList = QNetworkInterface::allAddresses();
    for (int i = 0; i < ipAddressesList.size(); i++)
        if (!ipAddressesList.at(i).isLoopback())
            ui->hostBox->addItem(ipAddressesList.at(i).toString());

    for (int i = 0; i < ipAddressesList.size(); i++)
        if (ipAddressesList.at(i).isLoopback())
            ui->hostBox->addItem(ipAddressesList.at(i).toString());

    serverSocket = new QTcpSocket(this);

    connect(ui->quitButton, SIGNAL(clicked()), this, SLOT(close()));
    connect(ui->sendButton, SIGNAL(clicked()), this, SLOT(sendMessage()));
    connect(ui->connectButton, SIGNAL(clicked()), this, SLOT(tryConnect()));
    connect(serverSocket, SIGNAL(readyRead()), this, SLOT(startReading()));
    connect(serverSocket, SIGNAL(error(QAbstractSocket::SocketError)), this, SLOT(displayError(QAbstractSocket::SocketError)));
    connect(serverSocket, SIGNAL(disconnected()), this, SLOT(serverDisconnected()));
    connect(serverSocket, SIGNAL(connected()), this, SLOT(disableAddressChange()));
    connect(serverSocket, SIGNAL(disconnected()), this, SLOT(enableAddressChange()));

    QNetworkConfigurationManager manager;
    if (manager.capabilities() & QNetworkConfigurationManager::NetworkSessionRequired)
    {
        QSettings settings(QSettings::UserScope, QLatin1String("QtProject"));
        settings.beginGroup(QLatin1String("QtNetwork"));
        const QString id = settings.value(QLatin1String("DefaultNetworkConfiguration")).toString();
        settings.endGroup();

        QNetworkConfiguration config = manager.configurationFromIdentifier(id);
        if ((config.state() & QNetworkConfiguration::Discovered) != QNetworkConfiguration::Discovered)
            config = manager.defaultConfiguration();

        networkSession = new QNetworkSession(config, this);
        connect(networkSession, SIGNAL(opened()), this, SLOT(sessionOpened()));

        networkSession->open();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startReading()
{
    QDataStream in(serverSocket);
    in.setVersion(QDataStream::Qt_5_1);

    if (blockSize == 0)
    {
        if (serverSocket->bytesAvailable() < (int)sizeof(quint16))
            return;

        in >> blockSize;
    }

    if (serverSocket->bytesAvailable() < blockSize)
        return;

    blockSize = 0;
    QString newMessage;
    in >> newMessage;
    ui->textEdit->textCursor().insertText("Server: " + newMessage + '\n');
}

void MainWindow::sendMessage()
{
    QString str = ui->messageLine->text();
    if (!isNotSpaces(str))
        return;
    ui->sendButton->setEnabled(false);

    QByteArray block;
    QDataStream out(&block, QIODevice::WriteOnly);
    ui->messageLine->clear();

    out << (quint16)str.length();
    out << str;
    serverSocket->write(block);

    ui->textEdit->textCursor().insertText("You: " + str + '\n');
    ui->sendButton->setEnabled(true);
}

void MainWindow::sessionOpened()
{
    QNetworkConfiguration config = networkSession->configuration();
    QString tmp;
    if (config.type() == QNetworkConfiguration::UserChoice)
        tmp = networkSession->sessionProperty(QLatin1String("UserChoiceConfiguration")).toString();
    else
        tmp = config.identifier();

    enableSendButton();
}

void MainWindow::displayError(QAbstractSocket::SocketError socketError)
{
    serverSocket->close();
    switch (socketError)
    {
        case QAbstractSocket::RemoteHostClosedError:
            break;

        case QAbstractSocket::HostNotFoundError:
            QMessageBox::information(this, "Client",
                                           "The host was not found. Please check the "
                                           "host name and port settings.");
            break;

        case QAbstractSocket::ConnectionRefusedError:
            QMessageBox::information(this, "Client",
                                           "The connection was refused by the peer. "
                                           "Make sure the fortune server is running, "
                                           "and check that the host name and port "
                                           "settings are correct.");
            break;

        default:
            QMessageBox::information(this, "Client",
                                           "The following error occurred: " + (serverSocket->errorString()));
    }
    enableAddressChange();
}

void MainWindow::enableSendButton()
{
    ui->sendButton->setEnabled((!networkSession || networkSession->isOpen()) &&
                                !ui->hostBox->currentText().isEmpty() &&
                                !ui->portLine->text().isEmpty());
}

void MainWindow::serverDisconnected()
{
    ui->sendButton->setEnabled(false);
    enableAddressChange();
    QMessageBox::warning(this, "Warning!", "Disconnected");
}

void MainWindow::enableAddressChange()
{
    ui->hostBox->setEnabled(true);
    ui->portLine->setEnabled(true);
}

void MainWindow::disableAddressChange()
{
    ui->hostBox->setEnabled(false);
    ui->portLine->setEnabled(false);
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

void MainWindow::tryConnect()
{
    if (ui->connectButton->text() == "Disconnect")
    {
        ui->connectButton->setText("Connect");
        serverSocket->close();
        ui->textEdit->setText("");
        ui->messageLine->setEnabled(false);
        disableSmiles();
        return;
    }

    disableAddressChange();
    serverSocket->connectToHost(ui->hostBox->currentText(), ui->portLine->text().toInt());

    if (serverSocket->waitForConnected(3000))
    {
        enableSendButton();
        ui->messageLine->setEnabled(true);
        enableSmiles();
        ui->connectButton->setText("Disconnect");
    }
    else
    {
        QMessageBox::information(this, "Client", "Connection timed out");
        enableAddressChange();
        ui->messageLine->setEnabled(false);
        disableSmiles();
    }
}

bool MainWindow::isNotSpaces(QString qStr)
{
    int length = qStr.length();

    for (int i = 0; i < length; ++i)
        if (qStr.at(i) != ' ')
            return true;

    return false;
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
