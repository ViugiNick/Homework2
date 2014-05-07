#pragma once
#include <QString>
#include "countinghash.h"

class HashTableInterface
{
    public:
        virtual ~HashTableInterface(){}
        virtual void add(QString &inputString) = 0;
        virtual void del(QString &inputString) = 0;
        virtual bool find(QString &inputString) = 0;
        virtual void deleteHashTable() = 0;
        virtual int tableSize() = 0;
        virtual double loadFactor() = 0;
        virtual int numConflicts() = 0;
        virtual int maxConflicts() = 0;
        virtual void print() = 0;
};
