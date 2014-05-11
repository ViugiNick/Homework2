#include <cstdio>
#pragma once


class ListElement
{
    public:
        ListElement(int val);
        ListElement();
        int value();
        void makeValue(int val);

        void makeLink(ListElement * l);
        void makePrev(ListElement * l);

        ListElement * goToNext();
        void printElement();

    private:
        int val;
        ListElement * next = NULL;
        ListElement * prev = NULL;
};
