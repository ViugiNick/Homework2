#pragma once
#include "sortingcomparator.h"

class IntSortingComparator : public SortingComparator<int>
{
    public:
        ///Method, for comparing integers
        bool greater(int firstArgument, int secondArgument)
        {
            return (firstArgument > secondArgument);
        }
};
