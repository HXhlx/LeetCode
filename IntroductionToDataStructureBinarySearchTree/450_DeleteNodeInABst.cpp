#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (!root)
            return nullptr;
        if (root->val < key)
            root->right = deleteNode(root->right, key);
        else if (root->val > key)
            root->left = deleteNode(root->left, key);
        else
        {
            if (!root->left)
                return root->right;
            if (!root->right)
                return root->left;
            TreeNode *node = root->left;
            while (node->right)
                node = node->right;
            node->right = root->right;
            root = root->left;
        }
        return root;
    }
};