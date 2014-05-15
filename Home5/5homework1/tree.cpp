#include "tree.h"
#include "sumvertex.h"
#include "multvertex.h"
#include "negvertex.h"
#include "devvertex.h"
#include "numvertex.h"
#include <iostream>
#include <vector>
#include <QString>

using namespace std;

Tree::Tree(const std::string& str)
{
    std::vector <char> input;
    input.resize(0);

    for(int i = str.size(); i >= 0; i--)
    {
        input.push_back(str[i]);
    }

    head = buildTree(input);
}

Tree::~Tree()
{
    delete head;
}

std::string Tree::printTree()
{
    string answer;
    head->print(answer);
    return answer;
}

int Tree::calculateTree()
{
    return head->calculate();
}

bool isNumber(char c)
{
    return(c >= '0' && c <= '9');
}

int toInt(char c)
{
    return(c - '0');
}

TreeNode* Tree::buildTree(std::vector<char>& input)
{
    TreeNode* tmp;

    while((input.back() == ' ') || (input.back() == ')'))
        input.pop_back();

    if (input.back() == '(')
    {
        input.pop_back();

        if(input.back() == '+')
            tmp = new SumVertex();

        if(input.back() == '-')
            tmp = new NegVertex();

        if(input.back() == '*')
            tmp = new MultVertex();

        if(input.back() == '/')
            tmp = new NegVertex();

        input.pop_back();

        tmp->makeLeft(buildTree(input));
        tmp->makeRight(buildTree(input));
    }
    else
    {
        int number = 0;
        bool flag = false;

        if (input.back() == '-')
        {
            flag = true;
            input.pop_back();
        }

        while(isNumber(input.back()))
        {
            number *= 10;
            number += toInt(input.back());
            input.pop_back();
        }
        input.pop_back();

        if(flag)
            number *= -1;

        tmp = new NumVertex(number);
    }
    return tmp;
}
