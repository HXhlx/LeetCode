#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        int n = nums.size();
        deque<int> seq;
        vector<int> Max(n - k + 1);
        auto fun = [&seq, &nums](int i)
        {
            while (!seq.empty() && nums[seq.back()] <= nums[i])
                seq.pop_back();
            seq.emplace_back(i);
        };
        if (n == 0)
            return {};
        for (int i = 0; i < k; ++i)
            fun(i);
        for (int i = k; i <= n; ++i)
        {
            if (seq.front() < i - k)
                seq.pop_front();
            Max[i - k] = nums[seq.front()];
            if (i < n)
                fun(i);
        }
        return Max;
    }
};
TEST(HuaDongChuangKouDeZuiDaZhi, 1)
{
    Solution s;
    vector<int> nums{1, 3, -1, -3, 5, 3, 6, 7}, ans{3, 3, 5, 5, 6, 7}, res = s.maxSlidingWindow(nums, 3);
    ASSERT_EQ(ans.size(), res.size());
    EXPECT_EQ(ans, res);
}