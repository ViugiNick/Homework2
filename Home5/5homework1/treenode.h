#pragma once
#include <string>

class TreeNode
{
    public:
        TreeNode() {}
        virtual ~TreeNode() {}
        ///Calculate value of tree
        virtual int calculate() = 0;
        ///Print tree in std::string answer
        virtual void print(std::string &answer) = 0;

        ///Writes the left link
        void makeLeft(TreeNode * newLeft)
        {
            left = newLeft;
        }

        ///Writes the right link
        void makeRight(TreeNode * newRight)
        {
            right = newRight;
        }

    protected:
        TreeNode * left = nullptr;
        TreeNode * right = nullptr;
};
