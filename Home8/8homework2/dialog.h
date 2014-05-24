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
        explicit Dialog(QWidget *parent = 0);
        ~Dialog();

    public slots:

        void activatedSuxButton();
        void activatedRulezButton();
        void activatedBayanButton();
        void activatedLoadButton();
        void activatedNextButton();
        void loaded();
    private:
        void vote(int id, int change);
        void cantVote();
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
