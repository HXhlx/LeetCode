#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "TreeNode.hpp"
using namespace std;
class Solution
{
    pair<bool, short> AVL(TreeNode *node)
    {
        if (node)
        {
            auto [la, lh] = AVL(node->left);
            auto [ra, rh] = AVL(node->right);
            return {la && ra && abs(lh - rh) <= 1, max(lh, rh) + 1};
        }
        else
            return {true, 0};
    }

public:
    bool isBalanced(TreeNode *root)
    {
        return AVL(root).first;
    }
};