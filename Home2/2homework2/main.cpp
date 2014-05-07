#include "consoleout.h"
#include "fileout.h"
#include "testTable.h"
#include <iostream>

using namespace std;

int main()
{
    TestTable tableTester;
    QTest::qExec(&tableTester);

    int size = 0;

    cout << "Enter size of input array" << endl;
    cin >> size;
    int ** inputArray = new int * [size];

    cout << "Enter your array:" << endl;
    for (int i = 0; i < size; i++)
    {
        inputArray[i] = new int[size];
        for (int j = 0; j < size; ++j)
            cin >> inputArray[i][j];
    }

    char type;
    cout << "Enter '1' for console out." << endl;
    cout << "Enter '2' for file out." << endl;
    cin >> type;

    switch(type)
    {
        case '1':
        {
            cout << "Ok, console out..." << endl;
            ConsoleWriter toConsole;
            toConsole.write(inputArray, size);
            break;
        }
        case '2':
        {
            FileWriter toFile("a.out");
            toFile.write(inputArray, size);
            break;
        }
    }

    for (int i = 0; i < size; i++)
        delete[] inputArray[i];

    delete[] inputArray;
    return 0;
}
