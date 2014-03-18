#include <iostream>
#include "bsorter.h"
#include "qsorter.h"

const int maxN  = 100;
int inputArray1[maxN];
int inputArray2[maxN];

using namespace std;

int main()
{
    int n;
    cin >> n;

    for(int i = 0; i < n; i++)
        cin >> inputArray1[i];

    BSorter bSorting;
    bSorting.sort(inputArray1, n);

    for (int i = 0; i < n; ++i)
    {
        cout << inputArray1[i] << " ";
    }
    cout << endl << "***" << endl;

    QSorter qSorting;
    qSorting.sort(inputArray1, n);

    for (int i = 0; i < n; ++i)
    {
        cout << inputArray1[i] << " ";
    }
    cout << endl;

    return 0;
}
