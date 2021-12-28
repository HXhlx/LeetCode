#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int ans = INT_MAX, sum = 0;
        for (vector<int>::iterator s = nums.begin(), e = nums.begin(); e != nums.end(); ++e)
        {
            sum += *e;
            while (sum >= target)
            {
                ans = min(ans, int(distance(s, e) + 1));
                sum -= *s++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};