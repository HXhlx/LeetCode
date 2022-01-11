#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
class Solution
{
  public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
    {
        if (!root)
            return nullptr;
        if (root == p || root == q)
            return root;
        TreeNode *Left = lowestCommonAncestor(root->left, p, q), *Right = lowestCommonAncestor(root->right, p, q);
        return Left && Right ? root : Left ? Left : Right;
    }
};