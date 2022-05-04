#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "ListNode.hpp"
using namespace std;
class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        bool ls = false;
        ListNode *atn = new ListNode, *l = atn;
        stack<int> atn1, atn2;
        for (ListNode *ln1 = l1; ln1; ln1 = ln1->next)
            atn1.emplace(ln1->val);
        for (ListNode *ln2 = l2; ln2; ln2 = ln2->next)
            atn2.emplace(ln2->val);
        while (!atn1.empty() && !atn2.empty())
        {
            l->next = new ListNode(atn1.top() + atn2.top() + ls);
            l = l->next;
            ls = l->val / 10;
            l->val %= 10;
            atn1.pop();
            atn2.pop();
        }
        while (!atn1.empty())
        {
            l->next = new ListNode(atn1.top() + ls);
            l = l->next;
            ls = l->val /= 10;
            l->val %= 10;
            atn1.pop();
        }
        while (!atn2.empty())
        {
            l->next = new ListNode(atn2.top() + ls);
            l = l->next;
            ls = l->val /= 10;
            l->val %= 10;
            atn2.pop();
        }
        if (ls)
            l->next = new ListNode(ls);
        return atn->next;
    }
};