#include <cstdio>
#pragma once

class StackElement
{
    public:
        StackElement(int val);
        StackElement();
        int value();
        void makeValue(int val);

        void makeLink(StackElement * l);
        StackElement * goToNext();
        void printElement();

    private:
        int val;
        StackElement * next = NULL;
};
