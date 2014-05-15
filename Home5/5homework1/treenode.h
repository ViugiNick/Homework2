#pragma once
#include <string>

class TreeNode
{
    public:
        TreeNode() {}
        virtual ~TreeNode() {}
        virtual int calculate() = 0;
        virtual void print(std::string &answer) = 0;

        void makeLeft(TreeNode * newLeft)
        {
            left = newLeft;
        }

        void makeRight(TreeNode * newRight)
        {
            right = newRight;
        }

    protected:
        TreeNode * left = nullptr;
        TreeNode * right = nullptr;
};
