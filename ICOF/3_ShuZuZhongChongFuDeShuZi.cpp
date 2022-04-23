#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int findRepeatNumber(vector<int> &nums)
    {
        for (unsigned i = 0, n = nums.size(); i < n;)
        {
            if (nums[i] == i)
            {
                ++i;
                continue;
            }
            if (nums[nums[i]] == nums[i])
                return nums[i];
            swap(nums[i], nums[nums[i]]);
        }
        return EOF;
    }
};