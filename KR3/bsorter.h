#include "sortingcomparator.h"
#pragma once

/// Class, for sorting array with bubble sort
class BSorter
{
    public:
    /// Procedure, for sorting array with bubble sort (comparator 'compare')
        template <typename T>
        void sort(T * inputArray, int size, SortingComparator<T> &compare)
        {
            for(int i = 0; i < size; i++)
                for(int j = 0; j < size; j++)
                {
                    if(compare.greater(inputArray[i], inputArray[j]))
                    {
                        T tmp = inputArray[i];
                        inputArray[i] = inputArray[j];
                        inputArray[j] = tmp;
                    }
                }
        }
};
