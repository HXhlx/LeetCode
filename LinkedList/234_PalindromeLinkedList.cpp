#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "ListNode.hpp"
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
        while (slow)
        {
            r = slow->next;
            slow->next = pre;
            pre = slow;
            slow = r;
        }
        for (slow = head, fast = pre; fast; slow = slow->next, fast = fast->next)
            if (slow->val != fast->val)
                return false;
        return true;
    }
};
TEST(PalindromeLinkedList, 2)
{
    Solution s;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    EXPECT_FALSE(s.isPalindrome(head));
}