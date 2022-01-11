#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        int len = nums.size(), n = 1 << len;
        vector<int> s;
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; ++i)
        {
            s.clear();
            bool flag = true;
            for (int j = 0; j < len; ++j)
                if (i & 1 << j)
                {
                    if (j && (i >> (j - 1) & 1) == 0 && nums[j] == nums[j - 1])
                    {
                        flag = false;
                        break;
                    }
                    s.emplace_back(nums[j]);
                }
            if (flag)
                res.emplace_back(s);
        }
        return res;
    }
};