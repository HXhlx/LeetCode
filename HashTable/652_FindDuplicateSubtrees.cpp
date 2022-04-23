#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "TreeNode.hpp"
using namespace std;
class Solution
{
    array<wint_t, 10000> counts{};
    map<pair<int, pair<wint_t, wint_t>>, int> links;
    vector<TreeNode *> fds;
    wint_t index = 1;
    wint_t DFS(TreeNode *node)
    {
        if (node)
        {
            pair<int, pair<wint_t, wint_t>> cur{node->val, {DFS(node->left), DFS(node->right)}};
            if (links.find(cur) == links.end())
                links[cur] = index++;
            wint_t idx = links[cur];
            if (++counts[idx] == 2)
                fds.emplace_back(node);
            return idx;
        }
        else
            return 0;
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
        DFS(root);
        return fds;
    }
};