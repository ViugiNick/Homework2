#include <iostream>
#include <string>

#include "testTree.h"
#include "tree.h"

int main()
{
    TestTree treeTester;
    QTest::qExec(&treeTester);

    return 0;
}
