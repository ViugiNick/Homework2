#pragma once

#include <QObject>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QTextCodec>
#include <QtWebKit/QWebElement>
#include <QWebFrame>
#include <QWebPage>
#include <QWebView>
#include <QDomDocument>
#include <iostream>
#include <set>
#include "ui_dialog.h"

namespace Ui
{
    class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

    public:
        explicit Dialog(QWidget *parent = 0) :
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

        ~Dialog()
        {
            delete ui;
        }

    public slots:


        void activatedSuxButton()
        {
            if(used.count(ui->idLine->text().toInt()) > 0)
            {
                cantVote();
                return;
            }
            QString tmpURL = "http://bash.im/quote/" + quotes.at(currQuote).toPlainText().mid(1);
            usedQuote(ui->idLine->text().toInt());
            QUrl url(tmpURL);

            QNetworkRequest request(url);
            request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");

            QNetworkAccessManager *tmp = new QNetworkAccessManager(this);
            tmp->post(request, "/sux");

            quoteSux();
        }

        void activatedRulezButton()
        {
            if(used.count(ui->idLine->text().toInt()) > 0)
            {
                cantVote();
                return;
            }
            QString tmpURL = "http://bash.im/quote/" + quotes.at(currQuote).toPlainText().mid(1);
            usedQuote(ui->idLine->text().toInt());
            QUrl url(tmpURL);

            QNetworkRequest request(url);
            request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");

            QNetworkAccessManager *tmp = new QNetworkAccessManager(this);
            tmp->post(request, "/rulez");

            quoteRulez();
        }

        void activatedBayanButton()
        {
            if(used.count(ui->idLine->text().toInt()) > 0)
            {
                cantVote();
                return;
            }
            QString tmpURL = "http://bash.im/quote/" + quotes.at(currQuote).toPlainText().mid(1);
            usedQuote(ui->idLine->text().toInt());
            QUrl url(tmpURL);

            QNetworkRequest request(url);
            request.setHeader(QNetworkRequest::ContentTypeHeader,"application/x-www-form-urlencoded");

            QNetworkAccessManager *tmp = new QNetworkAccessManager(this);
            tmp->post(request, "/bayan");
        }

        void activatedLoadButton()
        {
            std::cerr << "!!!" << std::endl;
            ui->textOfQuote->setText("...");
            view = new QWebView();
            view->load(QUrl("http://bash.im/"));

            connect(view, SIGNAL(loadFinished(bool)), this, SLOT(loaded()));
        }

        void activatedNextButton()
        {
            currQuote = ((currQuote + 1 == numberOfQuotes) ? 0 : currQuote + 1);

            ui->textOfQuote->setText(quotes.at(currQuote).toPlainText());
            ui->idLine->setText(idsOfQuote.at(currQuote).toPlainText().mid(1));
            ui->ratingLine->setText(rating.at(currQuote).toPlainText());
        }

        void loaded()
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

    private:

        void usedQuote(int id)
        {
            used.insert(id);
        }

        void quoteRulez()
        {
            ui->ratingLine->setText(QString::number(ui->ratingLine->text().toInt() + 1));
        }

        void quoteSux()
        {
            ui->ratingLine->setText(QString::number(ui->ratingLine->text().toInt() - 1));
        }

        void cantVote()
        {
            flag = (flag + 1) % 2;
            if(flag == 0)
                ui->ratingLine->setText("(>_<)");
            else
                ui->ratingLine->setText("(=_=)");
        }

        Ui::Dialog *ui;
        int numberOfQuotes;
        int currQuote;

        QWebView *view;

        QWebElementCollection rating;
        QWebElementCollection idsOfQuote;
        QWebElementCollection quotes;

        std::set <int> used;
        int flag;
    };
