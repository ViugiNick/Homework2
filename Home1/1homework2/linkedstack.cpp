#include "linkedstack.h"

linkedStack::~linkedStack()
{
    deleteStack();
    delete head;
}

int linkedStack::size()
{
    int result = 0;
    StackElement * l = head->goToNext();

    while(l != NULL)
    {
        result++;
        l = l->goToNext();
    }

    return result;
}

int linkedStack::top()
{
    return head->goToNext()->value();
}

void linkedStack::push(int val)
{
    StackElement * temp = new StackElement();
    temp->makeValue(val);
    temp->makeLink(head->goToNext());
    head->makeLink(temp);
}

void linkedStack::pop()
{
    StackElement * tmp = head->goToNext();

    head->makeLink(tmp->goToNext());
    delete tmp;
}

void linkedStack::deleteStack()
{
    int size = this->size();

    for(int i = 0; i < size; i++)
        this->pop();
}

void linkedStack::printStack()
{
    int size = this->size();
    StackElement * tmp = head->goToNext();

    for(int i = 0; i < size; i++)
    {
        tmp->printElement();
        tmp = tmp->goToNext();
    }
    printf("\n");
}

bool linkedStack::findInStack(int val)
{
    StackElement * currentElement = head->goToNext();

    while(currentElement != NULL)
    {
        if(val == currentElement->value())
               return true;

        currentElement = currentElement->goToNext();
    }
    return false;
}


