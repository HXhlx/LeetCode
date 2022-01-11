#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
    TreeNode *invertTree(TreeNode *root)
    {
        if (!root)
            return nullptr;
        TreeNode *Left = invertTree(root->left), *Right = invertTree(root->right);
        root->left = Right;
        root->right = Left;
        return root;
    }
};