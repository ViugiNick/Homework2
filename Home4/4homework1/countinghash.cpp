#include "countinghash.h"

HashFunction::HashFunction(char type, int size)
{
    this->type = type;
    this->size = size;
}

int HashFunction::hash(const QString &inputString)
{
    int hash = 0;
    const int sizeOfString = inputString.length();
    const int p = 239017;

    if(type == '+')
    {
        for (int i = 0; i < sizeOfString; i++)
            hash = (hash + inputString[i].toLatin1()) % size;
    }

    if(type == '*')
    {
        for (int i = 0; i < inputString.length(); i++)
            hash = (hash * p  + inputString[i].toLatin1()) % size;
    }

    return hash;
}
