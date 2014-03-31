#include "fileout.h"
#include <iostream>
#include <fstream>

FileWriter::~FileWriter()
{
    fileOut.close();
}

FileWriter::FileWriter(const char * name)
{
    fileOut.open(name);
}

void FileWriter::print(int x)
{
    fileOut << x << " ";
}

