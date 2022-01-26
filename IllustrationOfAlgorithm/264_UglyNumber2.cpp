#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int nthUglyNumber(int n)
    {
        vector<int> nun(n, 1);
        for (wint_t i = 1, p2 = 0, p3 = 0, p5 = 0; i < n; ++i)
        {
            int n2 = nun[p2] * 2, n3 = nun[p3] * 3, n5 = nun[p5] * 5;
            nun[i] = min({n2, n3, n5});
            if (nun[i] == n2)
                ++p2;
            if (nun[i] == n3)
                ++p3;
            if (nun[i] == n5)
                ++p5;
        }
        return nun.back();
    }
};
TEST(UglyNumber2, 1)
{
    Solution s;
    EXPECT_EQ(s.nthUglyNumber(10), 12);
}
TEST(UglyNumber2, 2)
{
    Solution s;
    EXPECT_EQ(s.nthUglyNumber(1), 1);
}