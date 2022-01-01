#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "ListNode.h"
using namespace std;
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (head == nullptr)
            return true;
        ListNode *slow = head, *fast = head, *pre = nullptr, *r;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        while (fast)
        {
            r = fast->next;
            fast->next = pre;
            pre = fast;
            fast = r;
        }
        for (slow = head, fast = pre; fast; slow = slow->next, fast = fast->next)
            if (slow->val != fast->val)
                return false;
        return true;
    }
};