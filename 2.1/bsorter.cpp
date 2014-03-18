#include "bsorter.h"

void BSorter::sort(int * inputArray, int size)
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
        {
            if(inputArray[i] > inputArray[j])
            {
                inputArray[i] += inputArray[j];
                inputArray[j] = inputArray[i] - inputArray[j];
                inputArray[i] -= inputArray[j];
            }
        }
}

