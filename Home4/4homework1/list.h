#pragma once
#include <QString>

class List
{
    public:
        virtual ~List(){}
        virtual int size() = 0;
        virtual void insertToPosition(int pos, const QString &val) = 0;
        virtual void deleteOnPosition(int pos) = 0;
        virtual void deleteList() = 0;
        virtual QString printList() = 0;
        virtual bool findInList(const QString &val) = 0;
};
