#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int rob(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        int a = nums[0], b = max(nums[0], nums[1]), n = nums.size();
        for (int i = 2; i < n; ++i)
        {
            int temp = max(a + nums[i], b);
            a = b;
            b = temp;
        }
        return b;
    }
};