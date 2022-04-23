#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int sum = 0;
        for (vector<int> &a : points)
        {
            unordered_map<size_t, int> counts;
            for (vector<int> &b : points)
                ++counts[pow(a.front() - b.front(), 2) + pow(a.back() - b.back(), 2)];
            sum += accumulate(counts.begin(), counts.end(), 0, [](int s, pair<const size_t, int> &c)
                              { return s + c.second * (c.second - 1); });
        }
        return sum;
    }
};
TEST(NumberOfBoomerangs, 1)
{
    Solution s;
    vector<vector<int>> points{{0, 0}, {1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    EXPECT_EQ(s.numberOfBoomerangs(points), 20);
}