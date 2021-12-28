#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        if (!root)
            return {};
        stack<TreeNode *> nodes;
        vector<int> post;
        TreeNode *node = root, *r = nullptr;
        while (!nodes.empty() || node)
        {
            if (node)
            {
                nodes.emplace(node);
                node = node->left;
            }
            else
            {
                node = nodes.top();
                if (node->right && node->right != r)
                    node = node->right;
                else
                {
                    r = nodes.top();
                    nodes.pop();
                    post.emplace_back(r->val);
                    node = nullptr;
                }
            }
        }
        return post;
    }
};