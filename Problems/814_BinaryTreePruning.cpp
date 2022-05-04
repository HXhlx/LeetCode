#include <bits/stdc++.h>
#include "gtest/gtest.h"
#include "TreeNode.hpp"
using namespace std;
class Solution
{
public:
    TreeNode *pruneTree(TreeNode *root)
    {
        for (TreeNode *r = root; r;)
        {
            TreeNode *pt = r->left;
            if (pt)
            {
                while (pt->right && pt->right != r)
                    pt = pt->right;
                if (pt->right == r)
                {
                    pt->right = nullptr;
                }
                else
                {
                    pt->right = r;
                    r = r->left;
                    continue;
                }
            }
        }
        return root;
    }
};