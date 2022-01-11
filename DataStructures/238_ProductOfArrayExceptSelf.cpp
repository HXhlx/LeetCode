#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        int len = nums.size();
        vector<int> output(len, 1);
        for (int i = 1; i < len; ++i)
            output[i] = output[i - 1] * nums[i - 1];
        for (int r = 1, i = len - 1; i >= 0; --i)
        {
            output[i] *= r;
            r *= nums[i];
        }
        return output;
    }
};