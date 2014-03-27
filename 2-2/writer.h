#pragma once

class Writer
{
    public:
        virtual ~Writer(){}
        void write(int ** inputArray, int size);

    protected:
        bool printSquare(int * temp, int &index, int ** inputArray, int start, int finish);
        virtual void print(int x) = 0;
};
