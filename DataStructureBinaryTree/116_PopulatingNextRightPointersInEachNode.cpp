#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "Node.h"
using namespace std;
class Solution
{
public:
    Node *connect(Node *root)
    {
        if (!root)
            return nullptr;
        for (Node *Left = root; Left->left; Left = Left->left)
            for (Node *node = Left; node; node = node->next)
            {
                node->left->next = node->right;
                if (node->next)
                    node->right->next = node->next->left;
            }
        return root;
    }
};