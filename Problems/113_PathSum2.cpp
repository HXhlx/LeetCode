#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "TreeNode.hpp"
using namespace std;
class Solution
{
    vector<int> sums;
    vector<vector<int>> ps;
    void DFS(TreeNode *node, int targetSum)
    {
        sums.emplace_back(node->val);
        if (node->left == nullptr && node->right == nullptr && targetSum == 0)
            ps.emplace_back(sums);
        if (node->left)
            DFS(node->left, targetSum - node->left->val);
        if (node->right)
            DFS(node->right, targetSum - node->right->val);
        sums.pop_back();
    }

public:
    vector<vector<int>> pathSum(TreeNode *root, int targetSum)
    {
        if (root)
            DFS(root, targetSum - root->val);
        return ps;
    }
};