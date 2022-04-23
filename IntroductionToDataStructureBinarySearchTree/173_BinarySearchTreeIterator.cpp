#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "TreeNode.hpp"
using namespace std;
class BSTIterator
{
    vector<int> nodes;
    vector<int>::iterator p, e;
    void Inorder(TreeNode *node)
    {
        if (node)
        {
            Inorder(node->left);
            nodes.emplace_back(node->val);
            Inorder(node->right);
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        Inorder(root);
        p = nodes.begin();
        e = nodes.end();
    }
    int next()
    {
        return *p++;
    }
    bool hasNext()
    {
        return p != e;
    }
};