#include <iostream>
#include <cstdlib>
#include <cstring>
#include "arraystack.h"

using namespace std;

const int maxN = 1000;
const int maxSizeOfNumber = 10;
const int maxChar = 500;

int operation(char c, int a, int b)
{
    if(c == '+')
        return a + b;
    if(c == '*')
        return a * b;
    if(c == '-')
        return b - a;
    if(c == '/')
        return b / a;
}
bool isNumber(char c)
{
    return(c <= '9' && c >= '0');
}

int calculate(const char *inputString)
{
        int priority[maxChar];

        priority['+'] = 1;
        priority['-'] = 1;

        priority['*'] = 2;
        priority['/'] = 2;

        ArrayStack *stack1 = new ArrayStack();
        ArrayStack *stack2 = new ArrayStack();
        ArrayStack *stack3 = new ArrayStack();
        int sizeOfString = strlen(inputString);

        for (int i = 0; i < sizeOfString; i++)
        {
            if (inputString[i] == '*' || inputString[i] == '/' || inputString[i] == '+' || inputString[i] == '-')
            {
                if (stack2->size() != 0 && priority[-stack2->top()] == priority[inputString[i]])
                {
                    stack1->push(stack2->top());
                    stack2->pop();
                    stack2->push(-int(inputString[i]));
                }
                else
                {
                    stack2->push(-int(inputString[i]));
                }
                continue;
            }

            if (inputString[i] == '(')
            {
                stack2->push(-int(inputString[i]));
                continue;
            }

            if (inputString[i] == ')')
            {
                while (true)
                {
                    if (stack2->top() == -int('('))
                    {
                        stack2->pop();
                        break;
                    }

                    stack1->push(stack2->top());
                    stack2->pop();
                }
                continue;
            }

            if (inputString[i] != '(' && inputString[i] != ')')
            {
                int newElement = 0;

                while(isNumber(inputString[i]))
                {
                    newElement *= 10;
                    newElement += inputString[i] - '0';
                    i++;
                }
                i--;

                stack1->push(newElement);
            }
        }

        cerr << "!" << endl;

        while (stack2->size() != 0)
        {
            stack1->push(stack2->top());
            stack2->pop();
        }

        while (stack1->size() != 0)
        {
            stack3->push(stack1->top());
            stack1->pop();
        }

    //------------------------------

        delete stack1;
        ArrayStack *stack4 = new ArrayStack();

        while (stack3->size() > 0)
        {
            int curr1 = stack3->top();
            stack3->pop();

            if (curr1 > 0)
                stack4->push(curr1);
            else
            {
                int curr2 = stack4->top();
                stack4->pop();
                int curr3 = stack4->top();
                stack4->pop();

                stack4->push(operation(char(-curr1), curr2, curr3));
            }
        }

        int result = stack4->top();

        delete stack4;
        delete stack2;
        delete stack3;

        return result;
}
