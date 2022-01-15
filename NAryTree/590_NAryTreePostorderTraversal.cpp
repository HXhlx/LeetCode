#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "Node.h"
using namespace std;
class Solution
{
public:
    vector<int> postorder(Node *root)
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
                for (Node *n : node->children)
                    nodes.emplace(n);
            }
        }
        reverse(vals.begin(), vals.end());
        return vals;
    }
};