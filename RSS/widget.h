#ifndef WIDGET_H
#define WIDGET_H

#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkReply>
#include <QTextCodec>
#include <QtWebKit/QWebElement>
#include <QWebFrame>
#include <QWebPage>
#include <QWebView>
#include <QWidget>
#include <QWidget>
#include <QListWidget>
#include <set>
#include <vector>
#include <string>
#include <QPushButton>
#include "xmlsimplehendler.h"
#include <QString>
#include <map>
#include <QtXml>

namespace Ui {
class Widget;
}

class RSSWidget : public QWidget
{
    Q_OBJECT

public:
    explicit RSSWidget(QWidget *parent = 0);
    ~RSSWidget();

private slots:
    void generateListOfRSS();
    void addRSS();
    void deleteRSS();
    void pressOnTitle(QListWidgetItem *sender);
    void pressOnFeed();
    void parseRSS(QString name);
    void loaded();
    void updateFile();
    void update();

private:
    QString nameOfFile(QString str);
    Ui::Widget *ui;
    std::set <QString> feeds;
    int oldSize;
    int oldSizeOfTitles;
    int numberOfFeeds;
    std::set<QString> updatingFiles;

    QWebView *view;
    XmlSimpleHandler *handler = new XmlSimpleHandler();

    std::map <QPushButton *, QString> croses;
    std::map <QPushButton *, QString> buttons;
    std::map <QListWidgetItem *, QString> titles;
};

#endif // WIDGET_H
