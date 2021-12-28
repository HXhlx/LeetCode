#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        stack<TreeNode *> nodes;
        vector<int> pre;
        nodes.emplace(root);
        while (!nodes.empty())
        {
            TreeNode *node = nodes.top();
            nodes.pop();
            pre.emplace_back(node->val);
            if (node->right)
                nodes.emplace(node->right);
            if (node->left)
                nodes.emplace(node->left);
        }
        return pre;
    }
};