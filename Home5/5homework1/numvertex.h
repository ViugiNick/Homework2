#pragma once
#include <cstdio>
#include <cstdlib>
#include "treenode.h"
#include <string>

class NumVertex : public TreeNode
{
    public:
        NumVertex(int number) : value(number) {}

        int calculate()
        {
            return value;
        }

        std::string strtoint(int input)
        {
            std::string tmp;

            while(input > 0)
            {
                tmp = char(input + '0') + tmp;
                input /= 10;
            }
            return tmp;
        }

        void print(std::string &answer)
        {
            answer += strtoint(value);
            //printf("%d", value);
        }

        int value;
};
