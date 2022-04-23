#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    bool checkStraightLine(vector<vector<int>> &coordinates)
    {
        pair<int, int> csl(coordinates[1][0] - coordinates[0][0], coordinates[1][1] - coordinates[0][1]);
        for (vector<int> &c : coordinates)
            if (csl.first * (c[1] - coordinates[0][1]) != csl.second * (c[0] - coordinates[0][0]))
                return false;
        return true;
    }
};
TEST(CheckIfItIsAStraightLine, 1)
{
    Solution s;
    vector<vector<int>> coordinates{{1, 2}, {2, 3}, {3, 4}, {4, 5}, {5, 6}, {6, 7}};
    EXPECT_TRUE(s.checkStraightLine(coordinates));
}
TEST(CheckIfItIsAStraightLine, 1)
{
    Solution s;
    vector<vector<int>> coordinates{{1, 1}, {2, 2}, {3, 4}, {4, 5}, {5, 6}, {7, 7}};
    EXPECT_FALSE(s.checkStraightLine(coordinates));
}