#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
  public:
    int smallestRangeII(vector<int> &nums, int k)
    {
        sort(nums.begin(), nums.end());
        int sr2 = nums.back() - nums.front();
        for (wint_t i = 1; i < nums.size(); ++i)
            sr2 = min(sr2, max(nums.back() - k, nums[i - 1] + k) - min(nums.front() + k, nums[i] - k));
        return sr2;
    }
};
TEST(SmallestRange2, 1)
{
    Solution s;
    vector<int> nums{1};
    EXPECT_EQ(s.smallestRangeII(nums, 0), 0);
}
TEST(SmallestRange2, 2)
{
    Solution s;
    vector<int> nums{0, 10};
    EXPECT_EQ(s.smallestRangeII(nums, 2), 6);
}
TEST(SmallestRange2, 3)
{
    Solution s;
    vector<int> nums{1, 3, 6};
    EXPECT_EQ(s.smallestRangeII(nums, 3), 3);
}