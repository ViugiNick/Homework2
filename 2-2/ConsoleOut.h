#include "writer.h"

class ConsoleWriter : public Writer
{
    public:
        ~ConsoleWriter(){}
    private:
        void print(int x);
};
