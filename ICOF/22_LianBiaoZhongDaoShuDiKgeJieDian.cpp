#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "ListNode.hpp"
using namespace std;
class Solution
{
public:
    ListNode *getKthFromEnd(ListNode *head, int k)
    {
        ListNode *l = head, *r = head;
        for (int i = 0; i < k; ++i)
            r = r->next;
        while (r)
        {
            l = l->next;
            r = r->next;
        }
        return l;
    }
};