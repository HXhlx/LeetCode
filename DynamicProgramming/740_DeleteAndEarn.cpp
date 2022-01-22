#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int deleteAndEarn(vector<int> &nums)
    {
        int m = 0;
        map<int, int> sums;
        array<pair<int, int>, 2> dae{};
        for (int num : nums)
            sums[num] += num;
        for (pair<const int, int> &s : sums)
        {
            m = dae[1].first + 1 == s.first ? max(dae[0].second + s.second, dae[1].second) : dae[1].second + s.second;
            dae[0] = dae[1];
            dae[1] = {s.first, m};
        }
        return m;
    }
};
TEST(DeleteAndEarn, 1)
{
    Solution s;
    vector<int> nums{3, 4, 2};
    EXPECT_EQ(s.deleteAndEarn(nums), 6);
}
TEST(DeleteAndEarn, 2)
{
    Solution s;
    vector<int> nums{2, 2, 3, 3, 3, 4};
    EXPECT_EQ(s.deleteAndEarn(nums), 9);
}