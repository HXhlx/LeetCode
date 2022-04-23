#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int adjustLevel(int cnt)
    {
        vector<bool> al(cnt);
        for (wint_t i = 1; i <= cnt; ++i)
            for (wint_t j = i - 1; j < cnt; j += i)
                al[j] = !al[j];
        return count(al.begin(), al.end(), true);
    }
};
TEST(AdjustLevel, 1)
{
    Solution s;
    EXPECT_EQ(s.adjustLevel(4), 2);
}
TEST(AdjustLevel, 2)
{
    Solution s;
    EXPECT_EQ(s.adjustLevel(0), 0);
}
TEST(AdjustLevel, 3)
{
    Solution s;
    EXPECT_EQ(s.adjustLevel(2), 1);
}