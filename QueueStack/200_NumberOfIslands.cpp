#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int numIslands(vector<vector<char>> &grid)
    {
        int m = grid.size(), n = grid.front().size(), islands = 0;
        array<pair<int, int>, 4> direct{make_pair(0, 1), make_pair(1, 0), make_pair(-1, 0), make_pair(0, -1)};
        for (int r = 0; r < m; ++r)
            for (int c = 0; c < n; ++c)
                if (grid[r][c] == '1')
                {
                    ++islands;
                    grid[r][c] = '0';
                    queue<pair<int, int>> neighbor;
                    neighbor.emplace(r, c);
                    while (!neighbor.empty())
                    {
                        pair<int, int> rc = neighbor.front();
                        neighbor.pop();
                        for (pair<int, int> &d : direct)
                        {
                            int dr = rc.first + d.first, dc = rc.second + d.second;
                            if (dr >= 0 && dr < m && dc >= 0 && dc < n && grid[dr][dc] == '1')
                            {
                                neighbor.emplace(dr, dc);
                                grid[dr][dc] = '0';
                            }
                        }
                    }
                }
        return islands;
    }
};
TEST(NumberOfIslands, 1)
{
    Solution s;
    vector<vector<char>> grid{
        {'1', '1', '1', '1', '1', '0', '1', '1', '1', '1'},
        {'1', '0', '1', '0', '1', '1', '1', '1', '1', '1'},
        {'0', '1', '1', '1', '0', '1', '1', '1', '1', '1'},
        {'1', '1', '0', '1', '1', '0', '0', '0', '0', '1'},
        {'1', '0', '1', '0', '1', '0', '0', '1', '0', '1'},
        {'1', '0', '0', '1', '1', '1', '0', '1', '0', '0'},
        {'0', '0', '1', '0', '0', '1', '1', '1', '1', '0'},
        {'1', '0', '1', '1', '1', '0', '0', '1', '1', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
        {'1', '0', '1', '1', '1', '1', '1', '1', '1', '0'}};
    EXPECT_EQ(s.numIslands(grid), 2);
}