#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "ListNode.h"
using namespace std;
class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *pre = new ListNode(0, head), *node = pre;
        while (node->next && node->next->next)
            if (node->next->val == node->next->next->val)
                for (int x = node->next->val; node->next && node->next->val == x; node->next = node->next->next)
                    ;
            else
                node = node->next;
        return pre->next;
    }
};