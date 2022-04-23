#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int minFallingPathSum(vector<vector<int>> &matrix)
    {
        wint_t n = matrix.size();
        for (wint_t i = 0; i < n - 1; ++i)
        {
            matrix[i + 1][0] += min(matrix[i][0], matrix[i][1]);
            for (wint_t j = 1; j < n - 1; ++j)
                matrix[i + 1][j] += min({matrix[i][j - 1], matrix[i][j], matrix[i][j + 1]});
            matrix[i + 1][n - 1] += min(matrix[i][n - 2], matrix[i][n - 1]);
        }
        return *min_element(matrix.back().begin(), matrix.back().end());
    }
};
TEST(MinimumFallingPathSum, 1)
{
    Solution s;
    vector<vector<int>> matrix{{2, 1, 3}, {6, 5, 4}, {7, 8, 9}};
    EXPECT_EQ(s.minFallingPathSum(matrix), 13);
}
TEST(MinimumFallingPathSum, 2)
{
    Solution s;
    vector<vector<int>> matrix{{-19, 57}, {-40, -5}};
    EXPECT_EQ(s.minFallingPathSum(matrix), -59);
}