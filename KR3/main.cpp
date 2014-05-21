#include "testSorting.h"
#include "bsorter.h"
#include "intsortingcomparator.h"
#include "sortingcomparator.h"

int main()
{
    TestSorting sortTester;
    QTest::qExec(&sortTester);

    return 0;
}
