#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
    bool isMirror(TreeNode *Left, TreeNode *Right)
    {
        return Left && Right ? Left->val == Right->val && isMirror(Left->left, Right->right) && isMirror(Left->right, Right->left) : !(Left || Right);
    }
    bool isSymmetric(TreeNode *root)
    {
        return isMirror(root, root);
    }
};