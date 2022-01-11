#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        int diff = targetSum - root->val;
        return root->left || root->right || diff ? hasPathSum(root->left, diff) || hasPathSum(root->right, diff) : true;
    }
};