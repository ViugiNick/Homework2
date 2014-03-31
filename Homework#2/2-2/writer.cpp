#include "writer.h"
#include "iostream"

void Writer::write(int ** inputArray, int size)
{
    int * temp = new int[size * size];
    int index = 0;

    for(int i = (size / 2) - 1; i >= 0; i--)
        printSquare(temp, index, inputArray, i, size - 1 - i);

    if(size % 2 == 1)
        temp[index] = inputArray[size / 2][size / 2];

    for(int i = size * size - 1; i >= 0; i--)
        print(temp[i]);
    delete[] temp;
}

bool Writer::printSquare(int * temp, int &index, int ** inputArray, int start, int finish)
{
    for(int i = start; i <= finish; i++)
    {
        temp[index] = inputArray[start][i];
        index++;
    }
    for(int i = start + 1; i < finish; i++)
    {
        temp[index] = inputArray[i][finish];
        index++;
    }
    for(int i = finish; i >= start; i--)
    {
        temp[index] = inputArray[finish][i];
        index++;
    }
    for(int i = finish - 1; i > start; i--)
    {
        temp[index] = inputArray[i][start];
        index++;
    }
}
