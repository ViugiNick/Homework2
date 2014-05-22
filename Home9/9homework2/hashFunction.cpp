#include "hashFunction.h"
#include <iostream>

int abs(int value)
{
    if (value < 0)
		value = -value;
	return value;
}

int modBySize(int value, int hashSize)
{
    while (value < 0)
    {
        value += hashSize;
    }

    value = value % hashSize;

    //std::cerr << "Hash " << value << std::endl;

	return value;
}

HashFunction::HashFunction(int size)
{
    hashSize = size;
}

int HashFunction::hashByModSize(int value)
{
    //std::cerr << value << " " << hashSize << std::endl;

    return modBySize(value, hashSize);
}

int HashFunction::hashByFunctionFamily(int value)
{
	return (modBySize((37 * value + 41), hashSize));
}

int HashFunction::hashByNumSum(int value)
{
    //std::cerr << "!!!" << value << std::endl;
    int result = 0;
	value = abs(value);
	while (value != 0)
	{
		result += value % 10;
		value /= 10;
	}
    //std::cerr << "!!!" << result % hashSize << std::endl;
	return (result % hashSize);
}
