#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int minPathSum(vector<vector<int>> &grid)
    {
        partial_sum(grid[0].begin(), grid[0].end(), grid[0].begin());
        for (wint_t r = 1, m = grid.size(); r < m; ++r)
            grid[r][0] += grid[r - 1][0];
        for (wint_t r = 1, m = grid.size(), n = grid[0].size(); r < m; ++r)
            for (wint_t c = 1; c < n; ++c)
                grid[r][c] += min(grid[r - 1][c], grid[r][c - 1]);
        return grid.back().back();
    }
};