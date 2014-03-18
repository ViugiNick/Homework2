#include "sorter.h"
#pragma once

class QSorter : public Sorter
{
    public:
        void sort(int * inputArray, int size);
    private:
        void qSort(int left, int right, int * inputArray);
};
