#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>> &mat, int k)
    {
        wint_t m = mat.size(), n = mat[0].size();
        vector<vector<int>> block_c(m, vector<int>(n)), block_r(m, vector<int>(n));
        for (wint_t r = 0; r < m; ++r)
        {
            block_c[r].front() = accumulate(mat[r].begin(), mat[r].begin() + min((wint_t)k + 1, n), 0);
            for (short c = 1; c < n; ++c)
            {
                block_c[r][c] = block_c[r][c - 1];
                if (c - k > 0)
                    block_c[r][c] -= mat[r][c - k - 1];
                if (c + k < n)
                    block_c[r][c] += mat[r][c + k];
            }
        }
        for (wint_t c = 0; c < n; ++c)
        {
            block_r[0][c] = accumulate(block_c.begin(), block_c.begin() + min((wint_t)k + 1, m), 0, [c](int s, vector<int> &b)
                                       { return s + b[c]; });
            for (short r = 1; r < m; ++r)
            {
                block_r[r][c] = block_r[r - 1][c];
                if (r - k > 0)
                    block_r[r][c] -= block_c[r - k - 1][c];
                if (r + k < m)
                    block_r[r][c] += block_c[r + k][c];
            }
        }
        return block_r;
    }
};
TEST(MatrixBlockSum, 1)
{
    Solution s;
    vector<vector<int>> mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, res{{12, 21, 16}, {27, 45, 33}, {24, 39, 28}}, ans = s.matrixBlockSum(mat, 1);
    ASSERT_EQ(res.size(), ans.size());
    for (wint_t r = 0; r < 3; ++r)
    {
        ASSERT_EQ(res[r].size(), ans[r].size());
        EXPECT_TRUE(equal(res[r].begin(), res[r].end(), ans[r].begin()));
    }
}
TEST(MatrixBlockSum, 2)
{
    Solution s;
    vector<vector<int>> mat{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}}, res(3, vector<int>(3, 45)), ans = s.matrixBlockSum(mat, 2);
    ASSERT_EQ(res.size(), ans.size());
    for (wint_t r = 0; r < 3; ++r)
    {
        ASSERT_EQ(res[r].size(), ans[r].size());
        EXPECT_TRUE(equal(res[r].begin(), res[r].end(), ans[r].begin()));
    }
}