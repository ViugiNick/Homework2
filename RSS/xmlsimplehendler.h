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
        bool characters(const QString &ch);

        std::map <QString, QString> textOfFeed;
    private:
        QString title;
        bool isTitle = false;
        bool isDescription = false;
};
