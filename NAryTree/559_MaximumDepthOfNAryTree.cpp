#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "Node.h"
using namespace std;
class Solution
{
public:
    int maxDepth(Node *root)
    {
        if (!root)
            return 0;
        int h = 0;
        for (Node *node : root->children)
            h = max(h, maxDepth(node));
        return h + 1;
    }
};