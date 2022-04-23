#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        return __builtin_popcount(n);
    }
};
TEST(NumberOf1Bits, 1)
{
    Solution s;
    EXPECT_EQ(s.hammingWeight(11), 3);
}
TEST(NumberOf1Bits, 2)
{
    Solution s;
    EXPECT_EQ(s.hammingWeight(128), 1);
}
TEST(NumberOf1Bits, 3)
{
    Solution s;
    EXPECT_EQ(s.hammingWeight(4294967293), 31);
}