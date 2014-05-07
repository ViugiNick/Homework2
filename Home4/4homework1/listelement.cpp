#include "listelement.h"
#include <iostream>
#include <QString>

ListElement::ListElement(QString val)
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

void ListElement::makeValue(QString &val)
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

void ListElement::printElement()
{
    std::cout << val.toStdString();
}
