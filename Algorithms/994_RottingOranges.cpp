#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        int dxy[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}}, r = grid.size(), c = grid[0].size(), ones = 0, dist[r][c], minute = 0;
        queue<pair<int, int>> rottings;
        for (int m = 0; m < r; ++m)
            for (int n = 0; n < c; ++n)
                switch (grid[m][n])
                {
                case 2:
                    rottings.emplace(m, n);
                    dist[m][n] = 0;
                    break;
                case 1:
                    ++ones;
                case 0:
                    dist[m][n] = -1;
                }
        while (!rottings.empty())
        {
            pair<int, int> rotting = rottings.front();
            rottings.pop();
            for (int i = 0; i < 4; i++)
            {
                int x = rotting.first + dxy[i][0], y = rotting.second + dxy[i][1];
                if (x >= 0 && x < r && y >= 0 && y < c && dist[x][y] == -1 && grid[x][y])
                {
                    dist[x][y] = dist[rotting.first][rotting.second] + 1;
                    rottings.emplace(x, y);
                    if (grid[x][y] == 1)
                    {
                        minute = dist[x][y];
                        if (!--ones)
                            break;
                    }
                }
            }
        }
        return ones ? -1 : minute;
    }
};