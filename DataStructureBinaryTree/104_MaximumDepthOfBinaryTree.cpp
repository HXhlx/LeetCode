#include <bits/extc++.h>
#include "TreeNode.hpp"
using namespace std;
class Solution
{
public:
    int maxDepth(TreeNode *root)
    {
        return root ? max(maxDepth(root->left) + 1, maxDepth(root->right) + 1) : 0;
    }
};