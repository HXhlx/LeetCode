#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        stack<TreeNode *> nodes;
        vector<int> inorder;
        for (TreeNode *node = root; !nodes.empty() || node;)
        {
            while (node)
            {
                nodes.emplace(node);
                node = node->left;
            }
            if (!nodes.empty())
            {
                node = nodes.top();
                inorder.emplace_back(node->val);
                node = node->right;
                nodes.pop();
            }
        }
        return inorder;
    }
};