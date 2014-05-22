#include "countinghash.h"
#include <iostream>
#include "singlylinkedlist.h"
#include "tablerror.h"
#include "hashtable.h"
#include "hashTableInterface.h"
#include <algorithm>
#include <string>

using namespace std;

HashTable::HashTable(char type, int size)
{
    this->size = size;
    hashCounter = new HashFunction(type, size);
    hashList = new SinglyLinkedList[size];
}

HashTable::~HashTable()
{
    deleteHashTable();
    delete hashCounter;
}

void HashTable::add(const QString &inputString)
{
    if(find(inputString))
    {
        TableErrors::FindEqualVal error;
        throw error;
    }

    int newHash = hashCounter->hash(inputString);
    //std::cerr << "Count hash1 : " << newHash << std::endl;
    hashList[newHash].insertToPosition(0, inputString);
}

void HashTable::del(const QString &inputString)
{
    int tmp = hashCounter->hash(inputString);
    //std::cerr << "Count hash2 : " << tmp << std::endl;
    int pos = hashList[tmp].positionInList(inputString);
    //std::cerr <<  "ListBefore :";
    hashList[tmp].printList();
    //std::cerr << "!!!" << " " << pos << std::endl;

    if (pos != -1)
        hashList[tmp].deleteOnPosition(pos);
    else
    {
        TableErrors::NoSuchVal error;
        throw error;
    }
    //std::cerr <<  "ListAfter :";
    hashList[tmp].printList();
}

bool HashTable::find(const QString &inputString)
{
    int tmp = hashCounter->hash(inputString);
    return (hashList[tmp].findInList(inputString));
}

void HashTable::deleteHashTable()
{
    delete[] hashList;
}

double HashTable::loadFactor()
{
    double ans = 0;
    for (int i = 0; i < size; i++)
        ans += hashList[i].size();
    return ans / size;
}

int HashTable::numConflicts()
{
    int ans = 0;
    for (int i = 0; i < size; ++i)
        if (hashList[i].size() > 1)
            ans++;
    return ans;
}

int HashTable::maxConflicts()
{
    int ans = 0;
    for (int i = 0; i < size; ++i)
        ans = std::max(ans, hashList[i].size());

    return ans;
}

void HashTable::changeHashFunction(HashFunction * counter)
{
    delete hashCounter;
    hashCounter = counter;

    SinglyLinkedList * newList = new SinglyLinkedList[size];
    for (int i = 0; i < this->size; i++)
    {
        ListElement * tmp = hashList[i].getHead();
        while (tmp->goToNext() != NULL)
        {
            QString newString = tmp->goToNext()->value();
            newList[hashCounter->hash(newString)].insertToPosition(0, newString);
            tmp = tmp->goToNext();
        }
    }
    deleteHashTable();
    hashList = newList;
}

int HashTable::getHash(const QString &inputString)
{
    return hashCounter->hash(inputString);
}

QString intToStr(int x)
{
    QString result = "";
    while(x > 0)
    {
        result = char('0' + (x % 10)) + result;
        x /= 10;
    }
    return result;
}

QString HashTable::print()
{
    QString result = "";

    for (int i = 0; i < size; i++)
    {
        if (hashList[i].size() != 0)
        {
            result += intToStr(i);
            result += " > ";
            result += hashList[i].printList();

            //std::cerr << i << " " << result << std::endl;
        }
    }
    return result;
}
int HashTable::tableSize()
{
    return size;
}
