#include "sorter.h"
#pragma once

/// Class, for sorting array with quick sort
class QSorter : public Sorter
{
    public:
    /// Procedure, for sorting array with quick sort
        void sort(int * inputArray, int size);
    private:
    /// Recursive realisation of quick sort
        void qSort(int left, int right, int * inputArray);
};
