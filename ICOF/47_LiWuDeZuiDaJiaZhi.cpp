#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int maxValue(vector<vector<int>> &grid)
    {
        wint_t m = grid.size(), n = grid[0].size();
        vector<vector<int>> mv(m + 1, vector<int>(n + 1));
        for (wint_t r = 0; r < m; ++r)
            for (wint_t c = 0; c < n; ++c)
                mv[r + 1][c + 1] = grid[r][c] + max(mv[r][c + 1], mv[r + 1][c]);
        return mv[m][n];
    }
};