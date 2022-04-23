#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "ListNode.hpp"
using namespace std;
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        ListNode *resHead = new ListNode(0), *res = resHead;
        while (list1 && list2)
        {
            if (list1->val < list2->val)
            {
                res->next = list1;
                list1 = list1->next;
            }
            else
            {
                res->next = list2;
                list2 = list2->next;
            }
            res = res->next;
        }
        if (list1)
            res->next = list1;
        if (list2)
            res->next = list2;
        return resHead->next;
    }
};