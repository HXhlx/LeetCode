#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *node = root;
        while (node)
        {
            if (node->val == val)
                return node;
            node = node->val > val ? node->left : node->right;
        }
        return node;
    }
};