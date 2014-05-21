#pragma once

///Interface for comparator
template <typename T>
class SortingComparator
{
    public:
        ///Method, for comparing
        virtual bool greater(T firstArgument, T secondArgument) = 0;
};
