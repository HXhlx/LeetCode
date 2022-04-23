#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "ListNode.hpp"
using namespace std;
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;
        ListNode *pre = nullptr, *p = head, *r = head->next;
        head->next = nullptr;
        while (r)
        {
            pre = p;
            p = r;
            r = r->next;
            p->next = pre;
        }
        return p;
    }
};