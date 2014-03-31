#include "arraystack.h"
#include "calculator.h"
#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

const int maxN = 1000;

int main() {

    /*
    arrayStack *temp1 = new arrayStack();
    temp1->push(3);
    temp1->printStack();
    temp1->push(9);
    temp1->printStack();
    temp1->push(2);
    temp1->printStack();
    //printf("%d", temp1->size());
    delete temp1;
    */

    char inputString[maxN];
    cout << "Enter your expression:" << endl;
    cin.getline(inputString, maxN);

    printf("%d", calculate(inputString));

    return 0;
}
