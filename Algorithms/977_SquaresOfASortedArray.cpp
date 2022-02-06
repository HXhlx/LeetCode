#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        vector<int> ans(nums.size());
        for (int k = nums.size() - 1, i = 0, j = k; k >= 0; --k)
            ans[k] = pow(nums[nums[i] + nums[j] < 0 ? i++ : j--], 2);
        return ans;
    }
};