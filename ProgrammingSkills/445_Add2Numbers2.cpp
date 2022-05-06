#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "ListNode.hpp"
using namespace std;
class Solution
{
  public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *atn = nullptr;
        stack<int> atn1, atn2;
        while (l1)
        {
            atn1.emplace(l1->val);
            l1 = l1->next;
        }
        while (l2)
        {
            atn2.emplace(l2->val);
            l2 = l2->next;
        }
        for (bool al = false; !atn1.empty() || !atn2.empty() || al;)
        {
            ListNode *ln = new ListNode(al, atn);
            if (!atn1.empty())
            {
                ln->val += atn1.top();
                atn1.pop();
            }
            if (!atn2.empty())
            {
                ln->val += atn2.top();
                atn2.pop();
            }
            al = ln->val / 10;
            ln->val %= 10;
            atn = ln;
        }
        return atn;
    }
};