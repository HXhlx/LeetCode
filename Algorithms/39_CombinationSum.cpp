#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
    vector<int> comb;
    vector<vector<int>> combs;
    wint_t n;
    void DFS(vector<int> &candidates, int target, int idx)
    {
        if (idx == n)
            return;
        if (target == 0)
        {
            combs.emplace_back(comb);
            return;
        }
        DFS(candidates, target, idx + 1);
        if (target - candidates[idx] >= 0)
        {
            comb.emplace_back(candidates[idx]);
            DFS(candidates, target - candidates[idx], idx);
            comb.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        n = candidates.size();
        DFS(candidates, target, 0);
        return combs;
    }
};