#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    bool findRotation(vector<vector<int>> &mat, vector<vector<int>> &target)
    {
        wint_t i = 0, j = 0, n = mat.size();
        array<function<pair<wint_t, wint_t>(wint_t, wint_t)>, 4> funs{[n](wint_t x, wint_t y) -> pair<wint_t, wint_t>
                                                                      { return {x, y}; },
                                                                      [n](wint_t x, wint_t y) -> pair<wint_t, wint_t>
                                                                      { return {y, n - x - 1}; },
                                                                      [n](wint_t x, wint_t y) -> pair<wint_t, wint_t>
                                                                      { return {n - x - 1, n - y - 1}; },
                                                                      [n](wint_t x, wint_t y) -> pair<wint_t, wint_t>
                                                                      { return {n - y - 1, x}; }};
        for (auto &f : funs)
        {
            for (i = 0; i < n; ++i)
            {
                for (j = 0; j < n; ++j)
                {
                    auto [x, y] = f(i, j);
                    if (mat[i][j] != target[x][y])
                        break;
                }
                if (j != n)
                    break;
            }
            if (i == n && j == n)
                return true;
        }
        return false;
    }
};