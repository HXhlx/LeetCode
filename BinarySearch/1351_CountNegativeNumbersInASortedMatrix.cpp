#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        int cn = 0;
        for (wint_t m = grid.size(), n = grid.front().size(), r = 0, c = 0; r < m; ++r)
        {
            vector<int>::reverse_iterator it = find_if(grid[r].rbegin() + c, grid[r].rend(), [](int g)
                                                       { return g >= 0; });
            c = distance(grid[r].rbegin(), it);
            cn += c;
        }
        return cn;
    }
};