#include "listelement.h"
#include <iostream>
#include <QString>
#include <string>

ListElement::ListElement(const QString val)
{
    makeValue(val);
}

ListElement::ListElement()
{
    QString tmp = "0";
    makeValue(tmp);
}

QString &ListElement::value()
{
    return val;
}

void ListElement::makeValue(const QString &val)
{
    this->val = val;
}

void ListElement::makeLink(ListElement * l)
{
    next = l;
}

void ListElement::makePrev(ListElement * l)
{
    prev = l;
}

ListElement * ListElement::goToNext()
{
    return next;
}

QString ListElement::printElement()
{
    return val;
}
