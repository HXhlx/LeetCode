#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int rangeBitwiseAnd(int left, int right)
    {
        while (left < right)
            right &= right - 1;
        return right;
    }
};
TEST(BitwiseAndOfNumbersRange, 1)
{
    Solution s;
    EXPECT_EQ(s.rangeBitwiseAnd(5, 7), 4);
}
TEST(BitwiseAndOfNumbersRange, 2)
{
    Solution s;
    EXPECT_EQ(s.rangeBitwiseAnd(0, 0), 0);
}
TEST(BitwiseAndOfNumbersRange, 3)
{
    Solution s;
    EXPECT_EQ(s.rangeBitwiseAnd(1, 2147483647), 0);
}