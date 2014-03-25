#include "bsorter.h"

void BSorter::sort(int ** inputArray, int size)
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
        {
            if(inputArray[i][0] > inputArray[j][0])
            {
                for(int l = 0; l < size; l++)
                {
                    inputArray[i][l] += inputArray[j][l];
                    inputArray[j][l] = inputArray[i][l] - inputArray[j][l];
                    inputArray[i][l] -= inputArray[j][l];
                }
            }
        }
}

