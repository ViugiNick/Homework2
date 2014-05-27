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
    ///Updating left column (list of  feeds)
    void generateListOfRSS();
    ///Adding new feed
    void addRSS();
    ///Deleting feed
    void deleteRSS();
    ///Pressing  on title -> opening text of feed
    void pressOnTitle(QListWidgetItem *sender);
    ///Opening list  of titles
    void pressOnFeed();
    ///Parsing RSS from file name
    void parseRSS(QString name);
    ///RSS loaded
    void loaded();
    ///Updating following feed
    void updateFile();
    ///Updaing all feeds
    void update();

private:
    QString nameOfFile(QString str);
    Ui::Widget *ui;
    ///Setof all feeds
    std::set <QString> feeds;
    int oldSize;
    int oldSizeOfTitles;
    int numberOfFeeds;
    ///Set of  QStrings for updating
    std::set<QString> updatingFiles;

    QWebView *view;
    XmlSimpleHandler *handler = new XmlSimpleHandler();

    ///Map with crosses
    std::map <QPushButton *, QString> croses;
    ///Map with feeds
    std::map <QPushButton *, QString> buttons;
    ///Map with titles
    std::map <QListWidgetItem *, QString> titles;
};

#endif // WIDGET_H
