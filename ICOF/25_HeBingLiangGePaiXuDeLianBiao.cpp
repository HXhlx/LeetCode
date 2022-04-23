#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "ListNode.hpp"
using namespace std;
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *resHead = new ListNode(0), *res = resHead;
        while (l1 && l2)
        {
            if (l1->val < l2->val)
            {
                res->next = l1;
                l1 = l1->next;
            }
            else
            {
                res->next = l2;
                l2 = l2->next;
            }
            res = res->next;
        }
        if (l1)
            res->next = l1;
        if (l2)
            res->next = l2;
        return resHead->next;
    }
};