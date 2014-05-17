#pragma once
#include "hashTableInterface.h"
#include "singlylinkedlist.h"
#include "tablerror.h"
#include <string>

class HashTable : public HashTableInterface
{
    public:
        HashTable(char type, int size);
        ~HashTable();
        void add(const QString &inputString);
        void del(const QString &inputString);
        bool find(const QString &inputString);
        void deleteHashTable();
        double loadFactor();
        int numConflicts();
        int maxConflicts();
        void changeHashFunction(HashFunction * counter);
        int getHash(const QString &inputString);
        std::string print();
        virtual int tableSize();

    private:
        int size = 100;
        HashFunction * hashCounter;
        SinglyLinkedList * hashList;
};
