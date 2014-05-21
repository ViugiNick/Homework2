#include "arraystack.h"

using namespace std;

ArrayStack::ArrayStack() : top(-1), Stack()
{
}

void ArrayStack::push(int value)
{
    ++top;
    stackElements[top] = value;

    return;
}

int ArrayStack::pop()
{
    if (!isEmpty())
    {
    --top;

    return stackElements[top + 1];
    }
    else
        return INT_MIN;
}

bool ArrayStack::isEmpty()
{
    return (top < 0);
}

void ArrayStack::print()
{
    for (int i = 0; i <= top; ++i)
        cout << stackElements[i] << ' ';

    cout << '\n';

    return;
}

void ArrayStack::deleteTop()
{
    if (!isEmpty())
        --top;

    return;
}

int ArrayStack::takeTop()
{
    return stackElements[top];
}