#include "singlylinkedlist.h"
#include <QString>
#include <iostream>

singlyLinkedList::~singlyLinkedList()
{
    deleteList();
    delete head;
}

int singlyLinkedList::size()
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

void singlyLinkedList::insertToPosition(int pos, QString &val)
{
    ListElement * currentElement = head;

    for(int i = 0; i < pos; i++)
        currentElement = currentElement->goToNext();

    ListElement * temp = new ListElement();
    temp->makeValue(val);
    temp->makeLink(currentElement->goToNext());
    currentElement->makeLink(temp);
}

void singlyLinkedList::deleteOnPosition(int pos)
{
    //std::cerr << pos << std::endl;

    ListElement * currentElement = head;
    for(int i = 0; i < pos; i++)
        currentElement = currentElement->goToNext();
    //std::cerr << "omg" << std::endl;
    ListElement * temp = currentElement->goToNext();
    //std::cerr << "omg" << std::endl;
    if(pos == this->size())
        currentElement->makeLink(NULL);
    else
        currentElement->makeLink(temp->goToNext());
    //std::cerr << "omg" << std::endl;
    delete temp;
}

void singlyLinkedList::deleteList()
{
    int size = this->size();

    for(int i = 0; i < size; i++)
    {
        ListElement * temp = head->goToNext();
        head->makeLink(head->goToNext()->goToNext());
        delete temp;
    }
}

void singlyLinkedList::printList()
{
    ListElement * currentElement = head->goToNext();

    while(currentElement != NULL)
    {
        currentElement->printElement();
        currentElement = currentElement->goToNext();
    }
    printf("\n");
}

bool singlyLinkedList::findInList(QString &val)
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
int singlyLinkedList::positionInList(QString &val)
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

ListElement *singlyLinkedList::getHead()
{
    return head;
}
