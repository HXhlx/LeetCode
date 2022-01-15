#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "Node.h"
using namespace std;
class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        vector<int> vals;
        stack<Node *> nodes;
        if (root)
        {
            nodes.emplace(root);
            while (!nodes.empty())
            {
                Node *node = nodes.top();
                nodes.pop();
                vals.emplace_back(node->val);
                for_each(node->children.rbegin(), node->children.rend(), [&nodes](Node *n)
                         { nodes.emplace(n); });
            }
        }
        return vals;
    }
};