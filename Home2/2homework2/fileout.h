#pragma once

#include "writer.h"
#include <fstream>

using namespace std;

//Class for printing to the file
class FileWriter : public Writer
{
    public:
        ~FileWriter();
        //Constuctor, which open output file ('name')
    FileWriter(const char * name);
    private:
        //Procedure for printing an integer for the file
    void print(int x);
        ofstream fileOut;
};
