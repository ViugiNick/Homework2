#include "singlylinkedlist.h"
#include <QString>
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

void SinglyLinkedList::insertToPosition(int pos, const QString &val)
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

std::string SinglyLinkedList::printList()
{
    ListElement * currentElement = head->goToNext();

    std::string result = "";

    while(currentElement != NULL)
    {
        result += currentElement->printElement();
        currentElement = currentElement->goToNext();
    }
    return result;
}

bool SinglyLinkedList::findInList(const QString &val)
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
int SinglyLinkedList::positionInList(const QString &val)
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

ListElement *SinglyLinkedList::getHead()
{
    return head;
}
