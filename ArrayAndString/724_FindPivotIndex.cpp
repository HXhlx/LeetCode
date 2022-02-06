#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int s = accumulate(nums.begin(), nums.end(), 0), n = nums.size();
        for (int l = 0, ls = 0; l < n; ++l)
        {
            if (ls + nums[l] == s - ls)
                return l;
            ls += nums[l];
        }
        return EOF;
    }
};