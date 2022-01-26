#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int maxProduct(vector<int> &nums)
    {
        int c = nums[0];
        pair<int, int> m(nums[0], nums[0]);
        for_each(nums.begin() + 1, nums.end(), [&c, &m](int n)
                 {
                     m = minmax({n, m.first * n, m.second * n});
                     c = max(c, m.second);
                 });
        return c;
    }
};