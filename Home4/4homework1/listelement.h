#include <cstdio>
#include <QString>

#pragma once

class ListElement
{
    public:
        ListElement(const QString val);
        ListElement();
        QString &value();
        void makeValue(const QString &val);

        void makeLink(ListElement * l);
        void makePrev(ListElement * l);

        ListElement * goToNext();
        QString printElement();

    private:
        QString val;
        ListElement * next = NULL;
        ListElement * prev = NULL;
};
