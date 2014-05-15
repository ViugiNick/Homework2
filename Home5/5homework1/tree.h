#pragma once
#include <QString>
#include "treenode.h"
#include <vector>
#include <string>

class Tree
{
    public:
        Tree(const std::string& str);
        ~Tree();
        std::string printTree();
        int calculateTree();
    private:
        TreeNode *buildTree(std::vector<char>& input);
        TreeNode *head;
};
