#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "TreeNode.hpp"
using namespace std;
class Solution
{
public:
    TreeNode *mirrorTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        TreeNode *Left = mirrorTree(root->left), *Right = mirrorTree(root->right);
        root->left = Right;
        root->right = Left;
        return root;
    }
};