#include "bsorter.h"

void BSorter::sort(int ** inputArray, int size)
{
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
        {
            if(inputArray[0][i] > inputArray[0][j])
            {
                for(int l = 0; l < size; l++)
                {
                    inputArray[l][i] += inputArray[l][j];
                    inputArray[l][j] = inputArray[l][i] - inputArray[l][j];
                    inputArray[l][i] -= inputArray[l][j];
                }
            }
        }
}

