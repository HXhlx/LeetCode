#include "gtest/gtest.h"
#include <bits/extc++.h>
using namespace std;
class Solution
{
  public:
    vector<int> nextGreaterElements(vector<int> &nums)
    {
        wint_t n = nums.size();
        vector<int> nge(n, -1);
        stack<int> bs;
        for (wint_t i = 0; i < n * 2 - 1; ++i)
        {
            while (!bs.empty() && nums[bs.top()] < nums[i % n])
            {
                nge[bs.top()] = nums[i % n];
                bs.pop();
            }
            bs.emplace(i % n);
        }
        return nge;
    }
};