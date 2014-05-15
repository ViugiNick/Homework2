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
            bool flag = false;

            if(input < 0)
            {
                flag = true;
                input *= -1;
            }

            std::string tmp;

            while(input > 0)
            {
                tmp = char(input + '0') + tmp;
                input /= 10;
            }

            if(flag)
                tmp = '-' + tmp;

            return tmp;
        }

        void print(std::string &answer)
        {
            answer += strtoint(value);
            //printf("%d", value);
        }

        int value;
};
