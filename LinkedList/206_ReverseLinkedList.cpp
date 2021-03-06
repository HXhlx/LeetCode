#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "ListNode.hpp"
using namespace std;
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head)
            return nullptr;
        ListNode *pre = nullptr, *p = head, *r = head->next;
        while (p)
        {
            r = p->next;
            p->next = pre;
            pre = p;
            p = r;
        }
        return pre;
    }
};