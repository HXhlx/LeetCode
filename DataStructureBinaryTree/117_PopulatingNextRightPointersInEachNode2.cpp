#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "Node.hpp"
using namespace std;
class Solution
{
    void handle(Node *&next_start, Node *node, Node *&last)
    {
        if (last)
            last->next = node;
        if (!next_start)
            next_start = node;
        last = node;
    }

public:
    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;
        for (Node *start = root; start;)
        {
            Node *last = nullptr, *next_start = nullptr;
            for (Node *node = start; node; node = node->next)
            {
                if (node->left)
                    handle(next_start, node->left, last);
                if (node->right)
                    handle(next_start, node->right, last);
            }
            start = next_start;
        }
        return root;
    }
};