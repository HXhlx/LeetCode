#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        int diff = 0, target = nums.size() - 1;
        for (int i = target; i >= 0; --i, ++diff)
            if (nums[i] >= diff)
            {
                target = i;
                diff = 0;
            }
        return !target;
    }
};