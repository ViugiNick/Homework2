#include "testMySet.h"

int main()
{
    TestMySet setTester;
    QTest::qExec(&setTester);
    return 0;
}
