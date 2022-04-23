#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int minDistance(string word1, string word2)
    {
        wint_t m = word1.size(), n = word2.size();
        vector<vector<int>> md(m + 1, vector<int>(n + 1));
        iota(md.front().begin(), md.front().end(), 0);
        for (wint_t r = 1; r <= m; ++r)
            md[r].front() = r;
        for (wint_t r = 0; r < m; ++r)
            for (wint_t c = 0; c < n; ++c)
                md[r + 1][c + 1] = word1[r] == word2[c] ? md[r][c] : min(md[r + 1][c], md[r][c + 1]) + 1;
        return md[m][n];
    }
};