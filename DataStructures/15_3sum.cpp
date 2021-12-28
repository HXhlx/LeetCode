#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int low = 0, n = nums.size(), high = n - 1;
        vector<vector<int>> zero_sum;
        sort(nums.begin(), nums.end());
        if (n < 3 || nums.front() > 0 || nums.back() < 0)
            return {};
        while (low < high) {
            int mid = (low + high) >> 1;
            if (nums[mid] < 0)
                low = mid + 1;
            else if (nums[mid] > 0)
                high = mid;
            else
                low = high = mid;
        }
        while (nums[low] >= 0 && low--)
            ;
        while (nums[high] == 0 && ++high < n)
            ;
        for (int a = 0; a <= low; ++a) {
            if (a && nums[a] == nums[a - 1])
                continue;
            for (int b = a + 1, c = n - 1, sum = -nums[a]; c >= high; --c) {
                if (c < n - 1 && nums[c] == nums[c + 1])
                    continue;
                while (b < c && nums[b] + nums[c] < sum)
                    ++b;
                if (b == c)
                    break;
                if (nums[b] + nums[c] == sum)
                    zero_sum.push_back({ nums[a], nums[b], nums[c] });
            }
        }
        if (high - low > 3)
            zero_sum.push_back({ 0, 0, 0 });
        return zero_sum;
    }
};
TEST(ThreeSum, 1)
{
    Solution s;
    vector<int> nums { -1, 0, 1, 2, -1, -4 };
    vector<vector<int>> expect_sum { { -1, -1, 2 }, { -1, 0, 1 } }, zero_sum = s.threeSum(nums);
    ASSERT_EQ(expect_sum.size(), zero_sum.size());
    if (expect_sum.size())
        ASSERT_EQ(expect_sum[0].size(), zero_sum[0].size());
    for (wint_t i = 0; i < expect_sum.size(); ++i)
        for (wint_t j = 0; j < expect_sum[0].size(); ++j)
            EXPECT_EQ(expect_sum[i][j], zero_sum[i][j]);
}
TEST(ThreeSum, 2)
{
    Solution s;
    vector<int> nums { 1, 2, -2, -1 };
    vector<vector<int>> zero_sum = s.threeSum(nums);
    ASSERT_TRUE(zero_sum.empty());
}