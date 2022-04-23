#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int co = 0;
        unordered_map<int, int> sums;
        for (int a : nums1)
            for (int b : nums2)
                ++sums[a + b];
        for (int c : nums3)
            for (int d : nums4)
                if (sums.find(-c - d) != sums.end())
                    co += sums[-c - d];
        return co;
    }
};
TEST(sum, 1)
{
    Solution s;
    vector<int> nums1{1, 2}, nums2{-2, -1}, nums3{-1, 2}, nums4{0, 2};
    EXPECT_EQ(s.fourSumCount(nums1, nums2, nums3, nums4), 2);
}
TEST(sum, 2)
{
    Solution s;
    vector<int> nums1{0}, nums2{0}, nums3{0}, nums4{0};
    EXPECT_EQ(s.fourSumCount(nums1, nums2, nums3, nums4), 1);
}