#include <iostream>
#include "testPointer.h"

using namespace std;

int main()
{
    TestPointer pointerTester;
    QTest::qExec(&pointerTester);

    return 0;
}

