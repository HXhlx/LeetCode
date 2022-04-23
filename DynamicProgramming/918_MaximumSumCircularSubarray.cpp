#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int total = accumulate(nums.begin(), nums.end(), 0), maxSum = nums[0], curMax = 0, minSum = nums[0], curMin = 0;
        for (int &n : nums)
        {
            curMax = max(curMax + n, n);
            maxSum = max(maxSum, curMax);
            curMin = min(curMin + n, n);
            minSum = min(minSum, curMin);
        }
        return maxSum > 0 ? max(maxSum, total - minSum) : maxSum;
    }
};