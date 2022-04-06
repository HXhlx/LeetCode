#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        vector<int>::iterator it = lower_bound(nums.begin(), nums.end(), target);
        return it == nums.end() || *it != target ? EOF : distance(nums.begin(), it);
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