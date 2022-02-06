#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
    {
        wint_t m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<int> upwo(n);
        upwo[0] = obstacleGrid[0][0] == 0;
        for (vector<int> &og : obstacleGrid)
            for (wint_t c = 0; c < n; ++c)
                if (og[c])
                    upwo[c] = 0;
                else if (c && og[c - 1] == 0)
                    upwo[c] += upwo[c - 1];
        return upwo.back();
    }
};