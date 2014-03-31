#pragma once
#include "qsorter.h"


void QSorter::sort(int * inputArray, int size)
{
    qSort(0, size - 1, inputArray);
}

void QSorter::qSort(int left, int right, int * inputArray)
{
    int i = left;
    int j = right;
    int m = inputArray[(i + j) / 2];
    int temp = 0;

    do
    {
        while (inputArray[i] < m)
        {
            i++;
        }

        while (inputArray[j] > m)
        {
            j--;
        }

        if (i <= j)
        {
            temp = inputArray[i];
            inputArray[i] = inputArray[j];
            inputArray[j] = temp;
            i++;
            j--;
        }
    }
    while(i <= j);


    if (left < j)
    {
        qSort(left, j, inputArray);
    }

    if (i < right)
    {
        qSort(i, right, inputArray);
    }
}
