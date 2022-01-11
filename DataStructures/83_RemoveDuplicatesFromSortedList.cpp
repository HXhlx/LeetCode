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
        ListNode *node = head;
        while (node->next)
            if (node->val != node->next->val)
                node = node->next;
            else
            {
                ListNode *temp = node->next;
                node->next = node->next->next;
                delete temp;
            }
        return head;
    }
};