#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    int combinationSum4(vector<int>& nums, int target)
    {
        vector<int> cs(target + 1);
        cs[0] = 1;
        for (wint_t i = 1; i <= target; ++i)
            for (int& num : nums)
                if (num <= i && cs[i - num] < INT_MAX - cs[i])
                    cs[i] += cs[i - num];
        return cs.back();
    }
};