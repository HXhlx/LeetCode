#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int specialArray(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), greater<>());
        if (nums.back() >= nums.size())
            return nums.size();
        for (wint_t l = 1, r = nums.size(); l < r;)
        {
            wint_t x = (l + r) >> 1;
            if (nums[x] >= x)
                l = x + 1;
            else if (nums[x - 1] < x)
                r = x;
            else
                return x;
        }
        return EOF;
    }
};
TEST(SpecialArrayWithXElementsGreaterThanOrEqualX, 1)
{
    Solution s;
    vector<int> nums{3, 5};
    EXPECT_EQ(s.specialArray(nums), 2);
}
TEST(SpecialArrayWithXElementsGreaterThanOrEqualX, 2)
{
    Solution s;
    vector<int> nums{0, 0};
    EXPECT_EQ(s.specialArray(nums), -1);
}
TEST(SpecialArrayWithXElementsGreaterThanOrEqualX, 3)
{
    Solution s;
    vector<int> nums{0, 4, 3, 0, 4};
    EXPECT_EQ(s.specialArray(nums), 3);
}
TEST(SpecialArrayWithXElementsGreaterThanOrEqualX, 4)
{
    Solution s;
    vector<int> nums{3, 6, 7, 7, 0};
    EXPECT_EQ(s.specialArray(nums), -1);
}