#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
    bitset<8> vis;
    vector<int> perm;
    vector<vector<int>> perms;
    wint_t n;
    void backtrack(vector<int> &nums, int idx)
    {
        if (idx == n)
        {
            perms.emplace_back(perm);
            return;
        }
        for (wint_t i = 0; i < n; ++i)
        {
            if (vis[i] || i && nums[i] == nums[i - 1] && !vis[i - 1])
                continue;
            perm.emplace_back(nums[i]);
            vis.set(i);
            backtrack(nums, idx + 1);
            vis.set(i, false);
            perm.pop_back();
        }
    }

public:
    vector<vector<int>> permuteUnique(vector<int> &nums)
    {
        n = nums.size();
        sort(nums.begin(), nums.end());
        backtrack(nums, 0);
        return perms;
    }
};