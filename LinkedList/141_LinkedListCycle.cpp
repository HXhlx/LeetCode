#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "ListNode.hpp"
using namespace std;
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!(head && head->next))
            return false;
        for (ListNode *slow = head, *fast = head->next; slow != fast; slow = slow->next, fast = fast->next->next)
            if (!(fast && fast->next))
                return false;
        return true;
    }
};