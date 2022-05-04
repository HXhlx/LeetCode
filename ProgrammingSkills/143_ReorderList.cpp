#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "ListNode.hpp"
using namespace std;
class Solution
{
  public:
    void reorderList(ListNode *head)
    {
        ListNode *fast = head, *slow = head, *ri = nullptr;
        while (fast && fast->next)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast)
            slow = slow->next;
        while (slow)
        {
            ListNode *r = slow->next;
            slow->next = ri;
            ri = slow;
            slow = r;
        }
        for (ListNode *h = head, *r = ri; h;)
        {
            ListNode *t = h->next;
            h->next = r;
            h = t;
            if (t)
            {
                r->next = t;
                r = t->next;
            }
        }
    }
};