#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "ListNode.hpp"
#include "TreeNode.hpp"
using namespace std;
class Solution
{
    bool DFS(ListNode *head, TreeNode *root)
    {
        if (!head)
            return true;
        if (!root || root->val != head->val)
            return false;
        return DFS(head->next, root->left) || DFS(head->next, root->right);
    }

public:
    bool isSubPath(ListNode *head, TreeNode *root)
    {
        if (!root)
            return false;
        return DFS(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};