#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode *pre = head, *back = head;
        for (int i = 0; i < n && pre; i++)
            pre = pre->next;
        if (!pre)
        {
            ListNode *p = head;
            head = head->next;
            delete p;
            return head;
        }
        pre = pre->next;
        while (pre)
        {
            back = back->next;
            pre = pre->next;
        }
        ListNode *p = back->next;
        back->next = p->next;
        delete p;
        return head;
    }
};