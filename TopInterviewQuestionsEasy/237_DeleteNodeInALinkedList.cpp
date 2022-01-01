#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "ListNode.h"
using namespace std;
class Solution
{
public:
    void deleteNode(ListNode *node)
    {
        node->val = node->next->val;
        node->next = node->next->next;
    }
};