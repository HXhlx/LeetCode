#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int findTargetSumWays(vector<int> &nums, int target)
    {
        int sum = accumulate(nums.begin(), nums.end(), 0), neg = sum - target;
        if (neg < 0 || neg % 2)
            return 0;
        neg >>= 1;
        int dp[neg + 1];
        fill(dp, dp + neg + 1, 0);
        dp[0] = 1;
        for (int num : nums)
            for (int j = neg; j >= num; --j)
                dp[j] += dp[j - num];
        return dp[neg];
    }
};