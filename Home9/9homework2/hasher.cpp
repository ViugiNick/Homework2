#include <iostream>
#include <QList>

#include "hasher.h"
#include "hashFunction.h"

using namespace std;

Hasher::Hasher(int size):
    numOfRecords(0),
	numOfCollisions(0),
    type(byMod)
{
    this->hashSize = size;
    function = new HashFunction(size);
    hashTable = new QList<int>[size];
}

Hasher::~Hasher()
{
    delete[] hashTable;
    delete function;
}

int Hasher::calcHash(int value)
{
    switch (type)
	{
        case (byMod):
        {
            return (function->hashByModSize(value));
        }
        case (byFam):
        {
            return (function->hashByFunctionFamily(value));
        }
        case (bySum):
        {
            return (function->hashByNumSum(value));
        }
        default:
            return -1;
	}
}

void Hasher::removeFromHash(int value)
{
	if (!isContained(value))
		return;

	int hashValue = calcHash(value);
	hashTable[hashValue].removeOne(value);

	numOfRecords--;

	if (hashTable[hashValue].size() == 0)
		numOfCollisions--;
}

bool Hasher::isContained(int value)
{
    return (hashTable[calcHash(value)].contains(value));
}

int Hasher::findMaxCollision()
{
	if (numOfCollisions == 0)
		return 0;
	int maxCollision = 0;
	for(int i = 0; i < hashSize; i++)
	{
		if (hashTable[i].size() > maxCollision)
			maxCollision = hashTable[i].size();
	}
	return maxCollision;
}

void Hasher::printStatistic()
{
	std::cout << "Statistic of hash table:\n"
				 " Type of hash-function - ";
    switch (type)
	{
        case (byMod):
        {
            std::cout << "by mod of " << hashSize << std::endl;
            break;
        }
        case (byFam):
        {
            std::cout << "'37 * value + 41' by mod of " << hashSize << std::endl;
            break;
        }
        case (bySum):
        {
            std::cout << "by sum of the digits by mod of " << hashSize << std::endl;
            break;
        }
	}
	std::cout << " Size of hash table - " << hashSize << std::endl;
	std::cout << " Num of records - " << numOfRecords << std::endl;
	std::cout << " Num of collisions - " << numOfCollisions << std::endl;
	std::cout << " Max length of collions in one list - " << findMaxCollision() << std::endl;
	std::cout << " Load factor - " << (1.0 * numOfRecords / hashSize) << std::endl;
}

void Hasher::rehash(hashType val)
{
    changeHash(val);

	numOfRecords = 0;
	numOfCollisions = 0;

	QList<int> *tempTable = new QList<int>[hashSize];
	for (int i = 0; i < hashSize; i++)
	{
		tempTable[i] = QList<int>(hashTable[i]);
		hashTable[i].clear();
	}

    for (int i = 0; i < hashSize; i++)
		while (!tempTable[i].isEmpty())
		{
			addToHash(tempTable[i].first());
			tempTable[i].removeFirst();
		}

    delete[] tempTable;
}

void Hasher::changeHash(hashType val)
{
    type = val;
}

void Hasher::addToHash(int value)
{
    //std::cerr << "New" << value << std::endl;
    if (isContained(value))
    {
        //cerr << "?" << endl;
        return;
    }
    //std::cerr << "Done" << std::endl;

	int hashValue = calcHash(value);
    //std::cerr << "New" << hashValue << std::endl;
    hashTable[hashValue] << value;

	numOfRecords++;

	if (hashTable[hashValue].size() > 1)
		numOfCollisions++;
}
