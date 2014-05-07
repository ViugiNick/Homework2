#pragma once

#include "writer.h"

//Class for printing to console
class ConsoleWriter : public Writer
{
    public:
    ~ConsoleWriter(){}
    private:
        //procedure for printing an integer to console
    void print(int x);
};
