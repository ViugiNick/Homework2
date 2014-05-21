#include "sortingcomparator.h"

template <typename T>
class SortingComparator
{
    virtual bool greater(T firstArguent, T secondArguent) = 0;
}
