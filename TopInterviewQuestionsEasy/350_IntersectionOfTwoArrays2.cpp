#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> num;
        vector<int> nums, &minimum = nums1.size() <= nums2.size() ? nums1 : nums2, &maximum = nums1.size() > nums2.size() ? nums1 : nums2;
        for (int &m : minimum)
            ++num[m];
        for (int &m : maximum)
            if (num.count(m))
            {
                --num[m];
                nums.push_back(m);
                if (num[m] == 0)
                    num.erase(m);
            }
        return nums;
    }
};
TEST(intersection_of_two_arrays_ii, 1)
{
    Solution s;
    vector<int> nums1 = {1, 2, 2, 1}, nums2 = {2, 2}, nums = s.intersect(nums1, nums2), result = {2, 2};
    ASSERT_EQ(nums.size(), result.size());
    for (int i = 0; i < nums.size(); ++i)
        EXPECT_EQ(nums[i], result[i]);
}
TEST(intersection_of_two_arrays_ii, 2)
{
    Solution s;
    vector<int> nums1 = {4, 9, 5}, nums2 = {9, 4, 9, 8, 4}, nums = s.intersect(nums1, nums2), result = {4, 9};
    ASSERT_EQ(nums.size(), result.size());
    for (int i = 0; i < nums.size(); ++i)
        EXPECT_EQ(nums[i], result[i]);
}