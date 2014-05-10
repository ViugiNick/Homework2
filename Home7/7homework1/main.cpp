#include <QCoreApplication>
#include "bag.h"
#include "testbag.h"

int main()
{
    TestBag bagTester;
    QTest::qExec(&bagTester);

    return 0;
}
