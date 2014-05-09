#include "linkedstack.h"

LinkedStack::~LinkedStack()
{
    deleteStack();
    delete head;
}

int LinkedStack::size()
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

int LinkedStack::top()
{
    return head->goToNext()->value();
}

void LinkedStack::push(int val)
{
    StackElement * temp = new StackElement();
    temp->makeValue(val);
    temp->makeLink(head->goToNext());
    head->makeLink(temp);
}

void LinkedStack::pop()
{
    StackElement * tmp = head->goToNext();

    head->makeLink(tmp->goToNext());
    delete tmp;
}

void LinkedStack::deleteStack()
{
    int size = this->size();

    for(int i = 0; i < size; i++)
        this->pop();
}

void LinkedStack::printStack()
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

bool LinkedStack::findInStack(int val)
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


