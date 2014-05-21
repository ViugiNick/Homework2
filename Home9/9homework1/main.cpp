#include "arraystack.h"
#include "pointerstack.h"
#include "stackcalculatortest.h"

const int stringLength = 255;

using namespace std;

char* converToPostfixt(Stack *stack, char* expression);
void calculate(Stack *stack, char* expression, int i);
char *initStirng(int length);

int main()
{
    StackCalculatorTest test;
    QTest::qExec(&test);

    cout << '\n' << "Welcome to the program of stack calculator\n";
    cout << "Enter expression you want to calculate ";

    char *infixExpression = initStirng(stringLength);
    int i = 0;

    while (true)
    {
        infixExpression[i] = getchar();
        if (infixExpression[i] == '\n')
            break;

        i++;
    }

    Stack *stacks[2];
    stacks[0] = new PointerStack();
    stacks[1] = new ArrayStack();

    char *expression1 = converToPostfixt(stacks[0], infixExpression);
    char *expression2 = converToPostfixt(stacks[1], infixExpression);

    calculate(stacks[0], expression1, i);
    calculate(stacks[1], expression2, i);

    cout << "The result from pointer stack is ";
    stacks[0]->print();
    cout << "The result from array stack is ";
    stacks[1]->print();

    delete[] infixExpression;
    delete[] expression1;
    delete[] expression2;
    delete stacks[0];
    delete stacks[1];

    return 0;
}

char *initStirng(int length)
{
    char *string = new char[length];

    for (int i = 0; i < length; ++i)
        string[i] = '\0';

    return string;
}

char* converToPostfixt(Stack *stack, char* expression)
{
    int i = 0;
    char *result = initStirng(stringLength);

    for (unsigned int j = 0; expression[j] != '\n'; ++j)
    {
        if ((expression[j] >= '0') && (expression[j] <= '9'))
        {
            result[i] = expression[j];
            ++i;
            continue;
        }
        if ((expression[j] == '*') || (expression[j] == '/'))
        {
            if (!stack->isEmpty())
                while ((stack->takeTop() == '*') || (stack->takeTop() == '/'))
                {
                    result[i] = stack->pop();
                    ++i;
                    if (stack->isEmpty())
                        break;
                }
                stack->push(expression[j]);
                continue;
        }
        if ((expression[j] == '+') || (expression[j] == '-') || (expression[j] == '('))
        {
            stack->push(expression[j]);
            continue;
        }
        if (expression[i] == ')')
        {
            while (stack->takeTop() != '(')
            {
                result[i] = stack->pop();
                ++i;
            }
            stack->deleteTop();
            continue;
        }
    }

    while (!stack->isEmpty())
    {
        result[i] = stack->pop();
        ++i;
    }

    return result;
}

void calculate(Stack *stack, char* expression, int i)
{
    for (int j = 0; j < i; ++j)
    {
        if ((expression[j] >= '0') && (expression[j] <= '9'))
        {
            stack->push(expression[j] - '0');
            continue;
        }

        int temp1 = stack->pop();
        int temp2 = stack->pop();

        if (expression[j] == '+')
            stack->push(temp1 + temp2);

        if (expression[j] == '*')
            stack->push(temp1 * temp2);

        if (expression[j] == '-')
            stack->push(temp2 - temp1);

        if (expression[j] == '/')
            stack->push(temp2 / temp1);
    }

    return;
}