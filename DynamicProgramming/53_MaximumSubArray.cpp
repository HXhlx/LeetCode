#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int maxSubArray(vector<int> &nums)
    {
        int s = INT_MIN, ms = INT_MIN;
        for (int &i : nums)
        {
            s = s < 0 ? i : i + s;
            ms = max(s, ms);
        }
        return ms;
    }
};