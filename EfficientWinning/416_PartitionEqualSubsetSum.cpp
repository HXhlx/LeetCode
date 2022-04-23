#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    bool canPartition(vector<int> &nums)
    {
        wint_t sum = accumulate(nums.begin(), nums.end(), 0), Max = *max_element(nums.begin(), nums.end()), target = sum >> 1, n = nums.size();
        if (n < 2 || sum & 1 || Max > target)
            return false;
        vector<bool> cp(target + 1);
        cp[0] = true;
        for (wint_t i = 0; i < n; ++i)
            for (wint_t j = target, num = nums[i]; j >= num; --j)
                cp[j] = cp[j] | cp[j - num];
        return cp[target];
    }
};