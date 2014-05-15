#pragma once
#include <cstdio>
#include <cstdlib>
#include "treenode.h"

class SumVertex : public TreeNode
{
    public:
        SumVertex() {}

        int calculate()
        {
            return this->left->calculate()
                   +
                   this->right->calculate();
        }

        void print(std::string &answer)
        {
            //std::printf("(");
            answer += '(';
            left->print(answer);
            answer += " + ";
            //std::printf(" + ");
            right->print(answer);
            answer += ')';
            //std::printf(")");
        }
};
