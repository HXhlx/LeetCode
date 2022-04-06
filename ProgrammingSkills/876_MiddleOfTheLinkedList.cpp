#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "ListNode.hpp"
using namespace std;
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        for (ListNode *fast = head; fast && fast->next; fast = fast->next->next)
            slow = slow->next;
        return slow;
    }
};