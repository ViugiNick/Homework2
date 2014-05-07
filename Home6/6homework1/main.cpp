#include <iostream>
#include "MyError.h"

class MyClass
{
    public:
        ~MyClass()
        {
            std::cout << "MyClass exemplar destroyed here" << std::endl;
        }
};

int main()
{
    try
    {
        MyClass main;

        MyErrors::SimpleError error;
        throw error;
    }
    catch (MyErrors::SimpleError &)
    {
        std::cout << "Exception catched here" << std::endl;
    }

    return 0;
}
