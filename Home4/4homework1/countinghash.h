#pragma once

#include <QString>

class HashFunction
{
    public:
        HashFunction(char type, int size);
        int hash(const QString &inputString);
    private:
        int size;
        char type;
};
