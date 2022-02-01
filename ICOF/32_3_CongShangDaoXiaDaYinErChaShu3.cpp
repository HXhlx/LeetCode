#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        deque<TreeNode *> nodes;
        vector<vector<int>> values;
        if (root)
            nodes.emplace_back(root);
        for (wint_t i = 0; !nodes.empty(); ++i)
        {
            values.emplace_back(vector<int>());
            switch (i % 2)
            {
            case 0:
                for (wint_t len = nodes.size(); len; --len)
                {
                    TreeNode *node = nodes.front();
                    nodes.pop_front();
                    values.back().emplace_back(node->val);
                    if (node->left)
                        nodes.emplace_back(node->left);
                    if (node->right)
                        nodes.emplace_back(node->right);
                }
                break;
            case 1:
                for (wint_t len = nodes.size(); len; --len)
                {
                    TreeNode *node = nodes.back();
                    nodes.pop_back();
                    values.back().emplace_back(node->val);
                    if (node->right)
                        nodes.emplace_front(node->right);
                    if (node->left)
                        nodes.emplace_front(node->left);
                }
                break;
            }
        }
        return values;
    }
};