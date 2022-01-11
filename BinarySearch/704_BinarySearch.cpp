#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int low = 0, high = nums.size() - 1;
        while (low <= high)
        {
            int mid = (low + high) / 2;
            if (nums[mid] < target)
                low = mid + 1;
            else if (nums[mid] > target)
                high = mid - 1;
            else
                return mid;
        }
        return EOF;
    }
};
TEST(BinarySearch, 1)
{
    Solution s;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    EXPECT_EQ(s.search(nums, 9), 4);
}
TEST(BinarySearch, 2)
{
    Solution s;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    EXPECT_EQ(s.search(nums, 2), -1);
}
TEST(BinarySearch, 3)
{
    Solution s;
    vector<int> nums = {5};
    EXPECT_EQ(s.search(nums, 5), 0);
}