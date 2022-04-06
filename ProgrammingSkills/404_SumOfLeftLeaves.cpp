#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "TreeNode.hpp"
using namespace std;
class Solution
{
  public:
    int sumOfLeftLeaves(TreeNode *root)
    {
        int soll = 0;
        for (TreeNode *to = root; to;)
        {
            if (TreeNode *node = to->left; node)
            {
                if (!node->left && !node->right)
                    soll += node->val;
                while (node->right && node->right != to)
                    node = node->right;
                if (node->right == to)
                    node->right = nullptr;
                else
                {
                    node->right = to;
                    to = to->left;
                    continue;
                }
            }
            to = to->right;
        }
        return soll;
    }
};