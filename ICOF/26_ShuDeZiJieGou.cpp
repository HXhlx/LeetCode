#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"
using namespace std;
class Solution
{
    bool DFS(TreeNode *A, TreeNode *B)
    {
        if (B == nullptr)
            return true;
        if (A == nullptr || A->val != B->val)
            return false;
        return DFS(A->left, B->left) && DFS(A->right, B->right);
    }

public:
    bool isSubStructure(TreeNode *A, TreeNode *B)
    {
        return A && B && (DFS(A, B) || isSubStructure(A->left, B) || isSubStructure(A->right, B));
    }
};