#include <QCoreApplication>
#include "singlylinkedlist.h"
#include <iostream>
#include "testuniquelist.h"

int main()
{
    TestUniqueList ListTester;
    QTest::qExec(&ListTester);

    return 0;
}
