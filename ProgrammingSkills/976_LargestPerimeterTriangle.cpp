#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int largestPerimeter(vector<int> &nums)
    {
        sort(nums.begin(), nums.end());
        for (wint_t i = nums.size() - 1; i > 1; --i)
            if (nums[i] < nums[i - 1] + nums[i - 2])
                return accumulate(nums.begin() + i - 2, nums.begin() + i + 1, 0);
        return 0;
    }
};