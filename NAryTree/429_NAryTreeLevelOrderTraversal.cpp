#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "Node.hpp"
using namespace std;
class Solution
{
    vector<vector<int>> vals;
    void DFS(Node *node, wint_t l)
    {
        if (node)
        {
            if (vals.size() == l)
                vals.emplace_back(vector<int>());
            vals[l].emplace_back(node->val);
            for (Node *n : node->children)
                DFS(n, l + 1);
        }
    }

public:
    vector<vector<int>> levelOrder(Node *root)
    {
        DFS(root, 0);
        return vals;
    }
};