#include "stackelement.h"

StackElement::StackElement(int val)
{
    makeValue(val);
}

StackElement::StackElement()
{
    makeValue(0);
}

int StackElement::value()
{
    return val;
}

void StackElement::makeValue(int val)
{
    this->val = val;
}

void StackElement::makeLink(StackElement * l)
{
    next = l;
}

StackElement * StackElement::goToNext()
{
    return next;
}

void StackElement::printElement()
{
    printf("%d ", val);
}

