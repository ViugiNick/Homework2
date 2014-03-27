#include "calculator.h"

double Calculator::calculate(double inputNumber1, double inputNuber2, char operation)
{
    if(operation == '+')
        return inputNumber1 + inputNuber2;
    if(operation == '-')
        return inputNumber1 - inputNuber2;
    if(operation == '*')
        return inputNumber1 * inputNuber2;
    if(operation == '/')
    {
        if(inputNuber2 == 0)
            return 100500;

        return inputNumber1 / inputNuber2;
    }
}
