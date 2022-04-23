#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "ListNode.hpp"
using namespace std;
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {
        for (ListNode *slow = head, *fast = head; fast;)
        {
            slow = slow->next;
            if (fast->next == nullptr)
                return nullptr;
            fast = fast->next->next;
            if (slow == fast)
            {
                ListNode *p = head;
                while (p != slow)
                {
                    p = p->next;
                    slow = slow->next;
                }
                return p;
            }
        }
        return nullptr;
    }
};