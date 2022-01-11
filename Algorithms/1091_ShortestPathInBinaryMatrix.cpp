#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int shortestPathBinaryMatrix(vector<vector<int>> &grid)
    {
        array<pair<int, int>, 8> direct{{{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}};
        int n = grid.size();
        queue<pair<int, int>> points;
        if (grid[0][0])
            return EOF;
        if (n == 1)
            return 1;
        points.emplace(0, 0);
        grid[0][0] = 1;
        for (int len = 1; !points.empty(); ++len)
            for (int i = 0, l = points.size(); i < l; ++i)
            {
                pair<int, int> point = points.front();
                points.pop();
                for (pair<int, int> &d : direct)
                {
                    int x = point.first + d.first, y = point.second + d.second;
                    if (x >= 0 && x < n && y >= 0 && y < n && grid[x][y] == 0)
                    {
                        if (x == n - 1 && y == n - 1)
                            return len + 1;
                        points.emplace(x, y);
                        grid[x][y] = 1;
                    }
                }
            }
        return EOF;
    }
};
TEST(ShortestPathInBinaryMatrix, 1)
{
    Solution s;
    vector<vector<int>> grid{{0, 0, 0}, {1, 1, 0}, {1, 1, 0}};
    EXPECT_EQ(s.shortestPathBinaryMatrix(grid), 4);
}