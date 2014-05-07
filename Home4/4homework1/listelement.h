#include <cstdio>
#include <QString>
#pragma once

class ListElement
{
    public:
        ListElement(QString val);
        ListElement();
        QString &value();
        void makeValue(QString &val);

        void makeLink(ListElement * l);
        void makePrev(ListElement * l);

        ListElement * goToNext();
        void printElement();

    private:
        QString val;
        ListElement * next = NULL;
        ListElement * prev = NULL;
};
