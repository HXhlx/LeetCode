#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "Node.hpp"
using namespace std;
class Solution
{
public:
    Node *flatten(Node *head)
    {
        if (!head)
            return head;
        stack<Node *> lists;
        Node *node = new Node;
        lists.emplace(head);
        while (!lists.empty())
        {
            node->next = lists.top();
            lists.top()->prev = node;
            lists.pop();
            for (node = node->next; node->next || node->child; node = node->next)
                if (node->child)
                {
                    if (node->next)
                        lists.emplace(node->next);
                    node->next = node->child;
                    node->child->prev = node;
                    node->child = nullptr;
                }
        }
        node = head->prev;
        node->next = head->prev = nullptr;
        return head;
    }
};