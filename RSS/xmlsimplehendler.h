#pragma once
#include <QtXml>
#include <QXmlDefaultHandler>
#include <QtWidgets>
#include <QXmlAttributes>
#include <iostream>
#include <map>

class XmlSimpleHandler : public QXmlDefaultHandler
{
    public:

        bool startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts);
        bool endElement(const QString &namespaceURI, const QString &localName, const QString &qName);
        ///Parsing tag content
        bool characters(const QString &ch);

        ///Map of titles(from title to text of feed)
        std::map <QString, QString> textOfFeed;
    private:
        QString title;
        bool isTitle = false;
        bool isDescription = false;
};
