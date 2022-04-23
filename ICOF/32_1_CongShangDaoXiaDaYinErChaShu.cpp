#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "TreeNode.hpp"
using namespace std;
class Solution
{
public:
    vector<int> levelOrder(TreeNode *root)
    {
        queue<TreeNode *> nodes;
        TreeNode *node;
        vector<int> values;
        if (root)
            nodes.emplace(root);
        while (!nodes.empty())
        {
            node = nodes.front();
            nodes.pop();
            values.emplace_back(node->val);
            if (node->left)
                nodes.emplace(node->left);
            if (node->right)
                nodes.emplace(node->right);
        }
        return values;
    }
};