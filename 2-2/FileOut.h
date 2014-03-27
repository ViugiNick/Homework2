#include "writer.h"
#include <fstream>

using namespace std;

class FileWriter : public Writer
{
    public:
        ~FileWriter();
        FileWriter(const char * name);
    private:
        void print(int x);
        ofstream fileOut;
};
