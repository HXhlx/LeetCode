#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        queue<TreeNode *> nodes;
        TreeNode *node;
        vector<vector<int>> levels;
        nodes.emplace(root);
        while (!nodes.empty())
        {
            vector<int> level;
            size_t len = nodes.size();
            for (size_t l = 0; l < len; ++l)
            {
                node = nodes.front();
                nodes.pop();
                level.emplace_back(node->val);
                if (node->left)
                    nodes.emplace(node->left);
                if (node->right)
                    nodes.emplace(node->right);
            }
            levels.emplace_back(level);
        }
        return levels;
    }
};