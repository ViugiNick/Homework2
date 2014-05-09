#include "singlylinkedlist.h"

SinglyLinkedList::~SinglyLinkedList()
{
    deleteList();
    delete head;
}

int SinglyLinkedList::size()
{
    int result = 0;
    ListElement * l = head->goToNext();

    while(l != NULL)
    {
        result++;
        l = l->goToNext();
    }

    return result;
}

void SinglyLinkedList::insertToPosition(int pos, int val)
{
    ListElement * currentElement = head;

    for(int i = 0; i < pos; i++)
        currentElement = currentElement->goToNext();

    ListElement * temp = new ListElement();
    temp->makeValue(val);
    temp->makeLink(currentElement->goToNext());
    currentElement->makeLink(temp);
}

void SinglyLinkedList::deleteOnPosition(int pos)
{
    ListElement * currentElement = head;
    for(int i = 0; i < pos; i++)
        currentElement = currentElement->goToNext();

    ListElement * temp = currentElement->goToNext();
    currentElement->makeLink(currentElement->goToNext()->goToNext());
    delete temp;
}

void SinglyLinkedList::deleteList()
{
    int size = this->size();

    for(int i = 0; i < size; i++)
    {
        ListElement * temp = head->goToNext();
        head->makeLink(head->goToNext()->goToNext());
        delete temp;
    }
}

void SinglyLinkedList::printList()
{
    ListElement * currentElement = head->goToNext();

    while(currentElement != NULL)
    {
        currentElement->printElement();
        currentElement = currentElement->goToNext();
    }
    printf("\n");
}

bool SinglyLinkedList::findInList(int val)
{
    ListElement * currentElement = head->goToNext();

    while(currentElement != NULL)
    {
        if(val == currentElement->value())
               return true;

        currentElement = currentElement->goToNext();
    }
    return false;
}

