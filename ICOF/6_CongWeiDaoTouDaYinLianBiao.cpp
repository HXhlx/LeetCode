#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "ListNode.h"
using namespace std;
class Solution
{
    vector<int> l;
    void DFS(ListNode *node)
    {
        if (node->next)
            DFS(node->next);
        l.emplace_back(node->val);
    }

public:
    vector<int> reversePrint(ListNode *head)
    {
        if (head)
            DFS(head);
        return l;
    }
};