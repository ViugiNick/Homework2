//2-1
#include <iostream>
#include "bsorter.h"
#include "qsorter.h"

const int maxN  = 100;
int inputArray1[maxN];
int inputArray2[maxN];

using namespace std;

int main()
{
    cout << "Enter size of array:" << endl;
    int n;
    cin >> n;

    cout << "Enter you array:" << endl;

    for (int i = 0; i < n; i++)
    {
        cin >> inputArray1[i];
        inputArray2[i] = inputArray1[i];
    }

    BSorter bSorting;
    bSorting.sort(inputArray1, n);

    for (int i = 0; i < n; ++i)
    {
        cout << inputArray1[i] << " ";
    }
    cout << endl << "***" << endl;

    QSorter qSorting;
    qSorting.sort(inputArray2, n);

    for (int i = 0; i < n; ++i)
    {
        cout << inputArray2[i] << " ";
    }
    cout << endl;

    return 0;
}
