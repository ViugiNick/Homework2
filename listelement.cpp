#include "listelement.h"
#include <iostream>

ListElement::ListElement(int val)
{
    makeValue(val);
}

ListElement::ListElement()
{
    makeValue(0);
}

int ListElement::getValue()
{
    return value;
}

void ListElement::makeValue(int val)
{
    this->value = val;
}

void ListElement::takeNext(ListElement * le)
{
    next = le;
}

ListElement * ListElement::goToNext()
{
    return next;
}

void ListElement::printElement()
{
    std::cout << value;
}
