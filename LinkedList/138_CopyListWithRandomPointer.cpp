#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "Node.hpp"
using namespace std;
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        for (Node *node = head; node; node = node->next->next)
        {
            Node *New = new Node(node->val);
            New->next = node->next;
            node->next = New;
        }
        for (Node *node = head; node; node = node->next->next)
            if (node->random)
                node->next->random = node->random->next;
        Node *New = new Node(0);
        for (Node *p = head, *q = New; p; p = p->next)
        {
            q->next = p->next;
            p->next = p->next->next;
            q = q->next;
        }
        return New->next;
    }
};