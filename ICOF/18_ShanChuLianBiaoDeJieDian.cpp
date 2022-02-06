#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "ListNode.hpp"
using namespace std;
class Solution
{
public:
    ListNode *deleteNode(ListNode *head, int val)
    {
        ListNode *dn = new ListNode(0, head), *node = dn;
        while (node->next && node->next->val != val)
            node = node->next;
        if (node->next)
            node->next = node->next->next;
        return dn->next;
    }
};