#include "widget.h"
#include "ui_widget.h"
#include <QLineEdit>
#include <QPalette>
#include <QtWebKit>
#include <QMessageBox>
#include <QDebug>
#include <QTimer>
#include <QString>
#include <QTextEdit>
#include <iostream>
#include <QListWidgetItem>
#include <QFile>
#include <QImage>
#include <map>
#include <QtXml>
#include <QScrollArea>
#include <QTimer>
#include "xmlsimplehendler.h"

RSSWidget::RSSWidget(QWidget *parent) :
    QWidget(parent),
    oldSize(0),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &RSSWidget::addRSS);
    ui->textEdit->setReadOnly(true);

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    timer->start(5000);

    connect(ui->listOfTitles, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(pressOnTitle(QListWidgetItem*)));
    generateListOfRSS();
}

void RSSWidget::update()
{
    for(std::set<QString>::iterator it = feeds.begin(); it != feeds.end(); it++)
    {
        view = new QWebView();

        view->load(QUrl(*it));

        updatingFile = *it;

        connect(view, SIGNAL(loadFinished(bool)), this, SLOT(updateFile()));
        //std::cerr << (*it).toStdString() << " " << "Updated" << std::endl;
    }
}

void RSSWidget::updateFile()
{
    QString info = view->page()->mainFrame()->toHtml();
    QFile file(nameOfFile(updatingFile));
    std::cerr << nameOfFile(updatingFile).toStdString() << std::endl;

    if(file.open(QIODevice::WriteOnly))
    {
        file.write(info.toUtf8());
        file.close();
    }
}

RSSWidget::~RSSWidget()
{
    for(std::set<QString>::iterator it = feeds.begin(); it != feeds.end(); it++)
    {
        QFile::remove(nameOfFile(*it));
    }
    delete ui;
}

void RSSWidget::deleteRSS()
{
    QPushButton *button = dynamic_cast<QPushButton *>(sender());

    oldSize = feeds.size();
    feeds.erase(croses[button]);
    croses.erase(button);

    generateListOfRSS();
}

void RSSWidget::pressOnTitle(QListWidgetItem* sender)
{
    ui->textEdit->setText(handler->textOfFeed[titles[sender]]);
}

void RSSWidget::pressOnFeed()
{
    QPushButton *button = dynamic_cast<QPushButton *>(sender());

    parseRSS(buttons[button]);
    ui->listOfTitles->clear();

    int id = 0;
    titles.clear();

    for(std::map<QString, QString>::iterator it = handler->textOfFeed.begin(); it != handler->textOfFeed.end(); it++, id++)
    {
        QListWidgetItem *button = new QListWidgetItem((*it).first);
        titles[button] = (*it).first;
        button->setText((*it).first);

        ui->listOfTitles->addItem(button);
        button->setText((*it).first);
    }
}

void RSSWidget::generateListOfRSS()
{
    for (int i = oldSize; i >= 0; i--)
    {
        delete ui->cross->itemAt(i)->widget();
        delete ui->listOfRSS->itemAt(i)->widget();
    }

    int id = 0;
    croses.clear();
    for(std::set<QString>::iterator it = feeds.begin(); it != feeds.end(); it++, id++)
    {
        QPushButton *button1 = new QPushButton;
        QPushButton *button2 = new QPushButton;
        croses[button1] = *it;
        buttons[button2] = *it;

        button1->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        button2->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);

        ui->cross->addWidget(button1);
        ui->listOfRSS->addWidget(button2);

        connect(button1, &QPushButton::clicked, this, &RSSWidget::deleteRSS);
        connect(button2, &QPushButton::clicked, this, &RSSWidget::pressOnFeed);

        button1->setText("x");
        button2->setText(*it);
    }
}

QString RSSWidget::nameOfFile(QString str)
{
    std::string tempStr = str.toStdString();

    for(int i = 0; i < tempStr.size(); i++)
    {
        if(tempStr[i] == '/')
            tempStr[i] = '.';
        if(tempStr[i] == ':')
            tempStr[i] = '.';
    }
    return QString::fromStdString(tempStr);
}

void RSSWidget::parseRSS(QString name)
{
    QXmlSimpleReader *parser = new QXmlSimpleReader();
    parser->setContentHandler(handler);
    handler->textOfFeed.clear();

    QFile *file = new QFile(nameOfFile(name));

    if(file->open(QIODevice::ReadOnly))
    {
        parser->parse(new QXmlInputSource(file));
        file->close();
    }
    delete file;
}

void RSSWidget::addRSS()
{
    ui->textEdit->setText("Loading");
    view = new QWebView();

    view->load(QUrl(ui->lineEdit->text()));

    connect(view, SIGNAL(loadFinished(bool)), this, SLOT(loaded()));
}

void RSSWidget::loaded()
{
    ui->textEdit->setText("");
    QString info = view->page()->mainFrame()->toHtml();
    QString newButton = ui->lineEdit->text();

    std::cerr << newButton.toStdString() << " ! " << nameOfFile(newButton).toStdString() << std::endl;

    QFile file(nameOfFile(newButton));

    if(file.open(QIODevice::WriteOnly))
    {
        file.write(info.toUtf8());
    }
    file.close();
    oldSize = feeds.size();
    feeds.insert(newButton);
    generateListOfRSS();
}
