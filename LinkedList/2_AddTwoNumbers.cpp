#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "ListNode.h"
using namespace std;
class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        int f = 0;
        ListNode *head = new ListNode, *node = head, *a = l1, *b = l2;
        while (a && b)
        {
            node->next = new ListNode(a->val + b->val + f);
            node = node->next;
            f = node->val / 10;
            node->val -= 10 * f;
            a = a->next;
            b = b->next;
        }
        a = a ? a : b;
        while (a)
        {
            node->next = new ListNode(a->val + f);
            node = node->next;
            f = node->val / 10;
            node->val -= 10 * f;
            a = a->next;
        }
        if (f)
            node->next = new ListNode(f);
        return head->next;
    }
};