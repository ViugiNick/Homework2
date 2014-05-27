#include "xmlsimplehendler.h"

bool XmlSimpleHandler::startElement(const QString &namespaceURI, const QString &localName, const QString &qName, const QXmlAttributes &atts)
{
    if (qName == "title")
    {
        isTitle = true;
    }
    if (qName == "description")
    {
        isDescription = true;
    }

    return true;
}

bool XmlSimpleHandler::endElement(const QString &namespaceURI, const QString &localName, const QString &qName)
{

    if (qName == "title")
        isTitle = false;
    if (qName == "description")
        isDescription = false;

    return true;
}

bool XmlSimpleHandler::characters(const QString &ch)
{
    if(isTitle)
        title = ch;
    if(isDescription)
        textOfFeed[title] = ch;

    return true;
}
