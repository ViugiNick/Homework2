#include "linkedlist.h"
#include <iostream>


LinkedList::~LinkedList()
{
    deleteList();
    delete head;
}

int LinkedList::length()
{
    int result = 0;
    ListElement * le = head->goToNext();

    while(le != NULL)
    {
        result++;
        le = le->goToNext();
    }

    return result;
}

void LinkedList::insert(int pos, int val)
{
    ListElement * le = head;
    while(le->goToNext() != NULL && pos > 0)
    {
        pos--;
        le = le->goToNext();
    }

    if (pos != 0)
    {
        printf("Error!!!\n");
        deleteList();
        exit(0);
    }

    ListElement * newListElement = new ListElement();
    newListElement->makeValue(val);
    newListElement->takeNext(le->goToNext());
    le->takeNext(newListElement);
}

void LinkedList::deleteElement(int pos)
{
    ListElement * le = head;
    while(le->goToNext() != NULL && pos > 0)
    {
        pos--;
        le = le->goToNext();
    }

    if (le->goToNext() == NULL || pos > 0)
    {
        printf("Error!!!\n");
        deleteList();
        exit(0);
    }

    ListElement * newListElement = le->goToNext();
    le->takeNext(le->goToNext()->goToNext());
    delete newListElement;
}

void LinkedList::deleteList()
{
    int length = this->length();
    while(length > 0)
    {
        deleteElement(0);
        length--;
    }
}

void LinkedList::printList()
{
    ListElement * le = head->goToNext();

    while(le != NULL)
    {
        le->printElement();
        printf(" ");
        le = le->goToNext();
    }
}
