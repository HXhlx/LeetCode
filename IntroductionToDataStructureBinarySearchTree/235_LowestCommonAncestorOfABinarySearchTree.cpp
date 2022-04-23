#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "TreeNode.hpp"
using namespace std;
class Solution
{
public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        TreeNode *ancester = root;
        while (true)
        {
            if (p->val < ancester->val && q->val < ancester->val)
                ancester = ancester->left;
            else if (p->val > ancester->val && q->val > ancester->val)
                ancester = ancester->right;
            else
                break;
        }
        return ancester;
    }
};