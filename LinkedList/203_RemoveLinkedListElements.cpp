#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "ListNode.hpp"
using namespace std;
class Solution
{
public:
    ListNode *removeElements(ListNode *head, int val)
    {
        ListNode *extend = new ListNode(0, head), *p = extend;
        while (p->next)
            if (p->next->val == val)
            {
                ListNode *q = p->next;
                p->next = p->next->next;
                delete q;
            }
            else
                p = p->next;
        return extend->next;
    }
};