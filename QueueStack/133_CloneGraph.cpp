#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "Node.hpp"
using namespace std;
class Solution
{
    unordered_map<Node *, Node *> links;

public:
    Node *cloneGraph(Node *node)
    {
        if (!node)
            return nullptr;
        if (links.find(node) != links.end())
            return links[node];
        Node *New = new Node(node->val);
        New->neighbors.reserve(node->neighbors.size());
        links[node] = New;
        for_each(node->neighbors.begin(), node->neighbors.end(), [&New, this](Node *n)
                 { New->neighbors.emplace_back(cloneGraph(n)); });
        return New;
    }
};