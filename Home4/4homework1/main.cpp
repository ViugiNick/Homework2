#pragma once
#include <QCoreApplication>
#include <iostream>
#include "singlylinkedlist.h"
#include "hashtable.h"
#include "countinghash.h"
#include "testHashTable.h"

using namespace std;
\
int main()
{
    TestHashTable hashTableTester;
    QTest::qExec(&hashTableTester);

    //int sizeOfHashTable = 10;
    //HashTable mainTable(0, sizeOfHashTable);

    return 0;
}
