#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
    vector<string> pars;
    string par;
    void DFS(int l, int r, int n)
    {
        if (r == n)
        {
            pars.emplace_back(par);
            return;
        }
        if (l < n)
        {
            par.push_back('(');
            DFS(l + 1, r, n);
            par.pop_back();
        }
        if (r < l)
        {
            par.push_back(')');
            DFS(l, r + 1, n);
            par.pop_back();
        }
    }

public:
    vector<string> generateParenthesis(int n)
    {
        DFS(0, 0, n);
        return pars;
    }
};