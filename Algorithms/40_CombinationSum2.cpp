#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
    map<int, int> freq;
    vector<int> comb;
    vector<vector<int>> combs;
    int n;
    void DFS(vector<int> &candidates, int target, int idx)
    {
        if (target == 0)
        {
            combs.emplace_back(comb);
            return;
        }
        for (int i = idx; i < n && target - candidates[i] >= 0; ++i)
            if (i == idx || candidates[i] != candidates[i - 1])
            {
                comb.emplace_back(candidates[i]);
                DFS(candidates, target - candidates[i], i + 1);
                comb.pop_back();
            }
    }

public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        n = candidates.size();
        sort(candidates.begin(), candidates.end());
        DFS(candidates, target, 0);
        return combs;
    }
};