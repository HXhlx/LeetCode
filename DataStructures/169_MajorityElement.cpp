#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int majorityElement(vector<int> &nums)
    {
        int major = INT_MIN, c = 0;
        for (int n : nums)
            if (n == major)
                ++c;
            else if (--c < 0)
            {
                major = n;
                c = 1;
            }
        return major;
    }
};