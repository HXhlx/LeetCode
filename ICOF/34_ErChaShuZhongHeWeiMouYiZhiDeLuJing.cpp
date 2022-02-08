#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "TreeNode.hpp"
using namespace std;
class Solution
{
    vector<int> sums;
    vector<vector<int>> ps;
    void DFS(TreeNode *node, int target)
    {
        sums.emplace_back(node->val);
        if (node->left == nullptr && node->right == nullptr && target == 0)
            ps.emplace_back(sums);
        if (node->left)
            DFS(node->left, target - node->left->val);
        if (node->right)
            DFS(node->right, target - node->right->val);
        sums.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int target)
    {
        if (root)
            DFS(root, target - root->val);
        return ps;
    }
};