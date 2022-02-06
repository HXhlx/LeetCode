#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "TreeNode.hpp"
using namespace std;
class Solution
{
public:
    TreeNode *insertIntoBST(TreeNode *root, int val)
    {
        if (!root)
            return new TreeNode(val);
        for (TreeNode *&node = root; node;)
            if (node->val > val)
            {
                if (node->left)
                    node = node->left;
                else
                {
                    node->left = new TreeNode(val);
                    break;
                }
            }
            else
            {
                if (node->right)
                    node = node->right;
                else
                {
                    node->right = new TreeNode(val);
                    break;
                }
            }
        return root;
    }
};