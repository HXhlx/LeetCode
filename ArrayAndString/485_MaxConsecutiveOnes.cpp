#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int m = 0;
        vector<int>::iterator l = nums.begin();
        for (vector<int>::iterator r = nums.begin(); r != nums.end(); ++r)
            if (*r == 0)
            {
                m = max(m, int(distance(l, r)));
                l = r + 1;
            }
        return max(m, int(distance(l, nums.end())));
    }
};