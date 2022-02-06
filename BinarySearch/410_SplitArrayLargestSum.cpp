#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int splitArray(vector<int> &nums, int m)
    {
        int l = *max_element(nums.begin(), nums.end()), h = accumulate(nums.begin(), nums.end(), 0);
        while (l < h)
        {
            int mid = midpoint(l, h), sum = 0, c = 1;
            for (int n : nums)
            {
                sum += n;
                if (sum > mid)
                {
                    sum = n;
                    ++c;
                }
            }
            if (c > m)
                l = mid + 1;
            else
                h = mid;
        }
        return l;
    }
};