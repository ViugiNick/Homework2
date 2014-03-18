#include "arrayStack.h"
#include <iostream>
#include <cstdio>
#include <string.h>

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
        return a - b;
    if(c == '/')
        return a / b;
}

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

    int priority[maxChar];

    priority['+'] = 1;
    priority['-'] = 1;

    priority['*'] = 2;
    priority['/'] = 2;

    arrayStack *stack1 = new arrayStack();
    arrayStack *stack2 = new arrayStack();
    arrayStack *stack3 = new arrayStack();

    printf("Input size of your expression : \n");
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        char temp[maxSizeOfNumber];
        scanf("%s", &temp);

        if (temp[0] == '*' || temp[0] == '/' || temp[0] == '+' || temp[0] == '-')
        {
            if (stack2->size() != 0 && priority[-stack2->top()] == priority[temp[0]])
            {
                stack1->push(stack2->top());
                stack2->pop();
                stack2->push(-int(temp[0]));
            }
            else
            {
                stack2->push(-int(temp[0]));
            }
            continue;
        }

        if (temp[0] == '(')
        {
            stack2->push(-int(temp[0]));
            continue;
        }

        if (temp[0] == ')')
        {
            while (1)
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

        if (temp[0] != '(' && temp[0] != ')')
        {
            int newElement = 0;

            for (int i = 0; i < strlen(temp); i++)
            {
                newElement *= 10;
                newElement += temp[i] - '0';
            }

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
    arrayStack *stack4 = new arrayStack();

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

    printf("%d", stack4->top());

    delete stack4;
    delete stack2;
    delete stack3;


    return 0;
}
