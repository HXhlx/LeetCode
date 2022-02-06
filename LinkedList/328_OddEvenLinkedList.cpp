#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "ListNode.hpp"
using namespace std;
class Solution
{
public:
    ListNode *oddEvenList(ListNode *head)
    {
        if (!(head && head->next))
            return head;
        for (ListNode *odd = head, *even = head->next, *node = even->next; node; node = node->next)
        {
            ListNode *r = node->next;
            node->next = odd->next;
            odd->next = node;
            odd = odd->next;
            node = r;
            even->next = node;
            if (node)
                even = even->next;
            else
                return head;
        }
        return head;
    }
};