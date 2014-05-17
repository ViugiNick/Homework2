#pragma once
#include <QString>
#include <string>
#include "countinghash.h"

class HashTableInterface
{
    public:
        virtual ~HashTableInterface(){}
        virtual void add(const QString &inputString) = 0;
        virtual void del(const QString &inputString) = 0;
        virtual bool find(const QString &inputString) = 0;
        virtual int tableSize() = 0;
        virtual double loadFactor() = 0;
        virtual int numConflicts() = 0;
        virtual int maxConflicts() = 0;
        virtual std::string print() = 0;
};
