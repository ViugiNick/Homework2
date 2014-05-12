#pragma once
#include "hashtableinterface.h"
#include "singlylinkedlist.h"

class HashTable : public HashTableInterface
{
    public:
        HashTable(char type, int size);
        ~HashTable();
        void add(QString &inputString);
        void del(QString &inputString);
        bool find(QString &inputString);
        void deleteHashTable();
        double loadFactor();
        int numConflicts();
        int maxConflicts();
        void changeHashFunction(HashFunction * counter);
        int getHash(QString &inputString);
        void print();
        virtual int tableSize();

    private:
        int size = 100;
        HashFunction * hashCounter;
        singlyLinkedList * hashList;
};
