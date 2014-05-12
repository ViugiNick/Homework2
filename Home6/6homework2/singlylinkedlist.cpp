#include "singlylinkedlist.h"
#include "uniquelisterrors.h"
#include <iostream>

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

void SinglyLinkedList::deleteListElement(int val)
{
    //std::cerr << val << std::endl;
    //if(positionInList(val) == -1)
    //{
    //    UniqueListErrors::NoSuchVal error;
    //    throw error;
    //}
    deleteOnPosition(positionInList(val));
}

void SinglyLinkedList::insertToPosition(int pos, int val)
{
    //if(findInList(val))
    //{
    //    UniqueListErrors::FindEqualVal error;
    //    throw error;
    //}

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

int SinglyLinkedList::positionInList(int val)
{
    ListElement * currentElement = head->goToNext();
    int ans = 0;

    while(currentElement != NULL)
    {
        if(val == currentElement->value())
               return ans;

        currentElement = currentElement->goToNext();
        ans++;
    }
    return -1;
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

