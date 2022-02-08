#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<int> exchange(vector<int> &nums)
    {
        int m;
        for (int l = 0, h = nums.size() - 1; l < h; ++l, --h)
        {
            while (l < h && nums[l] & 1)
                ++l;
            while (l < h && (nums[h] & 1) == 0)
                --h;
            swap(nums[l], nums[h]);
        }
        return nums;
    }
};
TEST(DiaoZhengShuZuShunXuShiJiShuWeiYuOuShuQianMian, 1)
{
    Solution s;
    vector<int> nums{1, 2, 3, 4}, ans{1, 3, 2, 4}, res = s.exchange(nums);
    ASSERT_EQ(res.size(), ans.size());
    EXPECT_TRUE(equal(res.begin(), res.end(), ans.begin()));
}