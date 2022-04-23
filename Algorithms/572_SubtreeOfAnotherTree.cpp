#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "TreeNode.hpp"
using namespace std;
class Solution
{
    int l_null = SHRT_MAX - 1, r_null = SHRT_MAX;
    void DFS(vector<int> &v, TreeNode *node)
    {
        v.emplace_back(node->val);
        if (node->left)
            DFS(v, node->left);
        else
            v.emplace_back(l_null);
        if (node->right)
            DFS(v, node->right);
        else
            v.emplace_back(r_null);
    }

public:
    bool isSubtree(TreeNode *root, TreeNode *subRoot)
    {
        vector<int> r, s;
        if (!subRoot)
            return true;
        else if (!root)
            return false;
        DFS(r, root);
        DFS(s, subRoot);
        int rl = r.size(), sl = s.size();
        vector<int> fail(sl, -1);
        for (int i = 1, j = -1; i < sl; ++i)
        {
            while (j != -1 && s[i] != s[j + 1])
                j = fail[j];
            if (s[i] == s[j + 1])
                ++j;
            fail[i] = j;
        }
        for (int i = 0, j = -1; i < rl; ++i)
        {
            while (j != -1 && r[i] != s[j + 1])
                j = fail[j];
            if (r[i] == s[j + 1])
                ++j;
            if (j == sl - 1)
                return true;
        }
        return false;
    }
};