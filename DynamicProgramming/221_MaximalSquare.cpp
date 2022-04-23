#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int maximalSquare(vector<vector<char>> &matrix)
    {
        wint_t m = matrix.size(), n = matrix[0].size(), Max = 0;
        vector<vector<wint_t>> ms(m, vector<wint_t>(n));
        for (wint_t r = 0; r < m; ++r)
            for (wint_t c = 0; c < n; ++c)
            {
                ms[r][c] = matrix[r][c] - 48;
                Max = max(Max, ms[r][c]);
            }
        for (wint_t r = 1; r < m; ++r)
            for (wint_t c = 1; c < n; ++c)
                if (ms[r][c])
                {
                    ms[r][c] = min({ms[r - 1][c - 1], ms[r - 1][c], ms[r][c - 1]}) + 1;
                    Max = max(Max, ms[r][c]);
                }
        return Max * Max;
    }
};