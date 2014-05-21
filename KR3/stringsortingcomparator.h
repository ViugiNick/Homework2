#pragma once
#include "sortingcomparator.h"
#include <string>

class StringSortingComparator : public SortingComparator<std::string>
{
    public:
        ///Method, for comparing stings
        bool greater(std::string firstArgument, std::string secondArgument)
        {
            return (firstArgument.compare(secondArgument) < 0);
        }
};
