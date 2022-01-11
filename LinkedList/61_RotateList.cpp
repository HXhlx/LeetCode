#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "ListNode.h"
using namespace std;
class Solution
{
public:
    ListNode *rotateRight(ListNode *head, int k)
    {
        if (!(head && head->next))
            return head;
        int s = 1;
        ListNode *node = head;
        while (node->next)
        {
            ++s;
            node = node->next;
        }
        node->next = head;
        k = s - k % s;
        node = head;
        for (s = 1; s < k; ++s)
            node = node->next;
        head = node->next;
        node->next = nullptr;
        return head;
    }
};