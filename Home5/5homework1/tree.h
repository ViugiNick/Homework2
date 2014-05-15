#pragma once
#include <QString>
#include "treenode.h"
#include <vector>
#include <string>

class Tree
{
    public:
        ///Construct tree from input string
        Tree(const std::string& str);
        ~Tree();
        ///Return string, which is print of tree
        std::string printTree();
        ///Calculate value of tree
        int calculateTree();
    private:
        TreeNode *buildTree(std::vector<char>& input);
        TreeNode *head;
};
