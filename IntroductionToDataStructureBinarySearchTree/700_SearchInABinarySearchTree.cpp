#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "TreeNode.hpp"
using namespace std;
class Solution
{
public:
    TreeNode *searchBST(TreeNode *root, int val)
    {
        TreeNode *node = root;
        while (node && node->val != val)
            node = node->val > val ? node->left : node->right;
        return node;
    }
};