#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        for (unsigned l = 0, h = nums.size() - 1; l < h;)
        {
            unsigned m = (l + h) >> 1;
            if (nums[l] + nums[m] > target)
                h = m;
            else if (nums[m] + nums[h] < target)
                l = m + 1;
            else if (nums[l] + nums[h] > target)
                --h;
            else if (nums[l] + nums[h] < target)
                ++l;
            else
                return {nums[l], nums[h]};
        }
        return {};
    }
};