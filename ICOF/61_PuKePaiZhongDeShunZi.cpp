#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution {
public:
    bool isStraight(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        wint_t k = count(nums.begin(), nums.end(), 0);
        for (wint_t i = k + 1, n = nums.size(); i < n; ++i)
            if (nums[i] - nums[i - 1] > k + 1 || nums[i] == nums[i - 1])
                return false;
            else
                k -= nums[i] - nums[i - 1] - 1;
        return true;
    }
};