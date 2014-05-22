#ifndef HASHER_H
#define HASHER_H

#include <QtCore/QList>

#include "hashFunction.h"

/**
* @file hasher.h
*
* @section DESCRIPTION
*
* Hasher class implementation.
* The main class of program, in that implements an interface to work with hash tables.
*/

class Hasher
{
public:
	Hasher();

	bool isContained(int value);
	void addToHash(int value);
	void removeFromHash(int value);

	/// Changhed hash function.
	void changeHash(hashType type);

	/// Rehashed the table for new function.
	void rehash(hashType type);

	int calcHash(int value);

	int findMaxCollision();
	void printStatistic();

	/// Array of objects of List class.
	int const hashSize;
	QList<int> *hashTable;

	/// Statistics about hash table.
	int numOfRecords;
	int numOfCollisions;

	/// Hash function type.
	hashType hashType;
	HashFunction *function;
};

#endif // HASHER_H