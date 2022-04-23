#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "TreeNode.hpp"
using namespace std;
class Solution
{
    long pre = LONG_MIN;

public:
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return true;
        bool l = isValidBST(root->left);
        if (root->val <= pre)
            return false;
        pre = root->val;
        bool r = isValidBST(root->right);
        return l && r;
    }
};