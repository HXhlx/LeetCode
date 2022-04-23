#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        vector<int> lis;
        lis.emplace_back(nums[0]);
        for (int n : nums)
        {
            if (n > lis.back())
                lis.emplace_back(n);
            else
            {
                wint_t l = 0, h = lis.size() - 1;
                while (l < h)
                {
                    wint_t m = (l + h) >> 1;
                    if (lis[m] < n)
                        l = m + 1;
                    else
                        h = m;
                }
                lis[l] = n;
            }
        }
        return lis.size();
    }
};
TEST(LongestIncreasingSubsequence, 1)
{
    Solution s;
    vector<int> nums{4, 10, 4, 3, 8, 9};
    EXPECT_EQ(s.lengthOfLIS(nums), 3);
}