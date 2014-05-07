#pragma once

/// Interface of class, for printing
class Writer
{
    public:
        virtual ~Writer(){}
        ///Procedure for printig an array
    void write(int ** inputArray, int size);

    protected:
        ///Procedure for printing current square from array
    bool printSquare(int * temp, int &index, int ** inputArray, int start, int finish);
        ///Procedure for printing an integer
    virtual void print(int x) = 0;
};
