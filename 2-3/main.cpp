#include <iostream>
#include "bsorter.h"

using namespace std;

int main()
{
    int n = 0;
    cout << "Enter size of array" << endl;
    cin >> n;

    int ** inputArray = new int * [n];
    for (int i = 0; i < n; i++)
    {
        inputArray[i] = new int[n];
    }

    cout << "Enter your matrix" << endl;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> inputArray[i][j];

    BSorter bSorting;
    bSorting.sort(inputArray, n);

    cout << " = = =" << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << inputArray[i][j] << " ";
        cout << endl;
    }

    for (int i = 0; i < n; ++i)
        delete[] inputArray[i];
    delete[] inputArray;

    return 0;
}
