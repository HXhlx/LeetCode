#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
    int robRange(vector<int> &nums, int s, int e)
    {
        int a = nums[s], b = max(nums[s], nums[s + 1]);
        for (int i = s + 2; i <= e; ++i)
        {
            int t = b;
            b = max(a + nums[i], b);
            a = t;
        }
        return b;
    }

public:
    int rob(vector<int> &nums)
    {
        int len = nums.size();
        switch (len)
        {
        case 1:
            return nums[0];
        case 2:
            return max(nums[0], nums[1]);
        default:
            return max(robRange(nums, 0, len - 2), robRange(nums, 1, len - 1));
        }
    }
};