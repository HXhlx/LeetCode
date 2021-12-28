#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int maxAreaOfIsland(vector<vector<int>> &grid)
    {
        int dxy[4][2] = {{0, -1}, {-1, 0}, {1, 0}, {0, 1}}, S = 0, r = grid.size(), c = grid[0].size();
        for (int i = 0; i < r; ++i)
            for (int j = 0; j < c; ++j)
                if (grid[i][j])
                {
                    list<pair<int, int>> lands{make_pair(i, j)};
                    grid[i][j] = 0;
                    for (list<pair<int, int>>::iterator land = lands.begin(); land != lands.end(); ++land)
                        for (auto point : dxy)
                        {
                            int x = land->first + point[0], y = land->second + point[1];
                            if (x >= 0 && x < r && y >= 0 && y < c && grid[x][y])
                            {
                                lands.emplace_back(x, y);
                                grid[x][y] = 0;
                            }
                        }
                    S = max(S, int(lands.size()));
                }
        return S;
    }
};
TEST(MaxAreaOfIsland, 1)
{
    Solution s;
    vector<vector<int>> grid = {{0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0}, {0, 1, 0, 0, 1, 1, 0, 0, 1, 1, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0}, {0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0}};
    EXPECT_EQ(s.maxAreaOfIsland(grid), 6);
}
TEST(MaxAreaOfIsland, 2)
{
    Solution s;
    vector<vector<int>> grid = {{0, 0, 0, 0, 0, 0, 0, 0}};
    EXPECT_EQ(s.maxAreaOfIsland(grid), 0);
}
TEST(MaxAreaOfIsland, 3)
{
    Solution s;
    vector<vector<int>> grid = {{1, 1, 0, 0, 0}, {1, 1, 0, 0, 0}, {0, 0, 0, 1, 1}, {0, 0, 0, 1, 1}};
    EXPECT_EQ(s.maxAreaOfIsland(grid), 0);
}