#pragma once

#include "ui_dialog.h"
#include "dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    flag(0),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
    connect(ui->suxButton, SIGNAL(clicked()), this, SLOT(activatedSuxButton()));
    connect(ui->rulezButton, SIGNAL(clicked()), this, SLOT(activatedRulezButton()));
    connect(ui->bayanButton, SIGNAL(clicked()), this, SLOT(activatedBayanButton()));
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(activatedLoadButton()));
    connect(ui->nextButton, SIGNAL(clicked()), this, SLOT(activatedNextButton()));
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::activatedSuxButton()
{
    if(used.count(ui->idLine->text().toInt()) > 0)
    {
        cantVote();
        return;
    }
    QString tmpURL = "http://bash.im/quote/" + quotes.at(currQuote).toPlainText().mid(1);
    vote(ui->idLine->text().toInt(), -1);
    QUrl url(tmpURL);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");

    QNetworkAccessManager *tmp = new QNetworkAccessManager(this);
    tmp->post(request, "/sux");
}

void Dialog::activatedRulezButton()
{
    if(used.count(ui->idLine->text().toInt()) > 0)
    {
        cantVote();
        return;
    }
    QString tmpURL = "http://bash.im/quote/" + quotes.at(currQuote).toPlainText().mid(1);
    vote(ui->idLine->text().toInt(), 1);
    QUrl url(tmpURL);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");

    QNetworkAccessManager *tmp = new QNetworkAccessManager(this);
    tmp->post(request, "/rulez");
}

void Dialog::activatedBayanButton()
{
    if(used.count(ui->idLine->text().toInt()) > 0)
    {
        cantVote();
        return;
    }
    QString tmpURL = "http://bash.im/quote/" + quotes.at(currQuote).toPlainText().mid(1);
    vote(ui->idLine->text().toInt(), 0);
    QUrl url(tmpURL);

    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");

    QNetworkAccessManager *tmp = new QNetworkAccessManager(this);
    tmp->post(request, "/bayan");
}

void Dialog::activatedLoadButton()
{
    std::cerr << "!!!" << std::endl;
    ui->textOfQuote->setText("...");
    view = new QWebView();
    view->load(QUrl("http://bash.im/"));

    connect(view, SIGNAL(loadFinished(bool)), this, SLOT(loaded()));
}

void Dialog::activatedNextButton()
{
    currQuote = ((currQuote + 1 == numberOfQuotes) ? 0 : currQuote + 1);

    ui->textOfQuote->setText(quotes.at(currQuote).toPlainText());
    ui->idLine->setText(idsOfQuote.at(currQuote).toPlainText().mid(1));
    ui->ratingLine->setText(rating.at(currQuote).toPlainText());
}

void Dialog::loaded()
{
    quotes = view->page()->mainFrame()->findAllElements("div[class=text]");
    rating = view->page()->mainFrame()->findAllElements("span[class=rating]");
    idsOfQuote = view->page()->mainFrame()->findAllElements("a[class=id]");

    currQuote = -1;
    numberOfQuotes = quotes.toList().length();

    ui->bayanButton->setEnabled(true);
    ui->rulezButton->setEnabled(true);
    ui->suxButton->setEnabled(true);
    ui->nextButton->setEnabled(true);

    activatedNextButton();
}

void Dialog::vote(int id, int change)
{
    used.insert(id);
    ui->ratingLine->setText(QString::number(ui->ratingLine->text().toInt() + change));
}

void Dialog::cantVote()
{
    flag = (flag + 1) % 2;
    if(flag == 0)
        ui->ratingLine->setText("(>_<)");
    else
        ui->ratingLine->setText("(=_=)");
}
