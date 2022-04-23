#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;
        int small = INT_MAX, mid = INT_MAX;
        for (int num : nums)
            if (small >= num)
                small = num;
            else if (mid >= num)
                mid = num;
            else
                return true;
        return false;
    }
};