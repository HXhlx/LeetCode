#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        if (nums.size() < 3)
            return 0;
        int c = 0, t = 0, d = nums[1] - nums[0];
        for (vector<int>::iterator it = nums.begin() + 2; it != nums.end(); ++it)
        {
            int D = *it - *(it - 1);
            if (D == d)
                ++t;
            else
            {
                d = D;
                t = 0;
            }
            c += t;
        }
        return c;
    }
};