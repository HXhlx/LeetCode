#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "ListNode.hpp"
using namespace std;
class Solution
{
public:
    int getDecimalValue(ListNode *head)
    {
        int gdv = 0;
        for (ListNode *node = head; node; node = node->next)
            gdv = gdv * 2 + node->val;
        return gdv;
    }
};