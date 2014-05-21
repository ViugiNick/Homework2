#include "pointerstack.h"

using namespace std;

PointerStack::PointerStack() : top(nullptr), Stack()
{
}

PointerStack::~PointerStack()
{
    while (top != nullptr)
    {
        StackElement *temp = top->next;
        delete top;
        top = temp;
    };
}

void PointerStack::push(int value)
{
    StackElement *temp = new StackElement;
    temp->value = value;
    temp->next = top;
    top = temp;
}

int PointerStack::pop()
{
    if (isEmpty())
        return INT_MIN;

    int result = top->value;
    StackElement* temp = top;
    top = top->next;
    delete(temp);


    return result;
}

bool PointerStack::isEmpty()
{
    return (top == nullptr);
}

void PointerStack::print()
{
    StackElement *temp = top;
    while (temp != nullptr)
    {
            cout << temp->value << ' ';
            temp = temp->next;
    }

    cout << '\n';

    return;
}

void PointerStack::deleteTop()
{
    top = top->next;

    return;
}

int PointerStack::takeTop()
{
    return top->value;
}