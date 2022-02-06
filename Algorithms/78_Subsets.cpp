#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> subsets(vector<int> &nums)
    {
        int len = nums.size(), n = 1 << len;
        vector<int> s;
        vector<vector<int>> res;
        for (int i = 0; i < n; ++i)
        {
            s.clear();
            for (int j = 0; j < len; ++j)
                if (i & 1 << j)
                    s.emplace_back(nums[j]);
            res.emplace_back(s);
        }
        return res;
    }
};