#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int e = 0, m = 0, n = nums.size() - 1, s = 0;
        for (int i = 0; i < n; ++i)
            if (m >= i)
            {
                m = max(m, i + nums[i]);
                if (i == e)
                {
                    e = m;
                    ++s;
                }
            }
        return s;
    }
};