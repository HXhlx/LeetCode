#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "ListNode.hpp"
using namespace std;
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        ListNode *a = headA, *b = headB;
        while (a != b)
        {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }
        return a;
    }
};