#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> so;
        for (wint_t l = 0, r = matrix.front().size(), t = 0, b = matrix.size(); l < r && t < b; ++l, --r, ++t, --b)
        {
            so.insert(so.end(), matrix[t].begin() + l, matrix[t].begin() + r - 1);
            for (wint_t c = t; c < b; ++c)
                so.emplace_back(matrix[c][r - 1]);
            if (l + 1 < r && t + 1 < b)
            {
                so.insert(so.end(), matrix[b - 1].rbegin() + l + 1, matrix[b - 1].rbegin() + r - 1);
                for (wint_t c = b - 1; c > t; --c)
                    so.emplace_back(matrix[c][l]);
            }
        }
        return so;
    }
};
TEST(SpiralMatrix, 1)
{
    Solution s;
    vector<vector<int>> matrix{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    vector<int> so = s.spiralOrder(matrix), ms{1, 2, 3, 6, 9, 8, 7, 4, 5};
    EXPECT_EQ(so, ms);
}
TEST(SpiralMatrix, 2)
{
    Solution s;
    vector<vector<int>> matrix{{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    vector<int> so = s.spiralOrder(matrix), ms{1, 2, 3, 4, 8, 12, 11, 10, 9, 5, 6, 7};
    EXPECT_EQ(so, ms);
}
TEST(SpiralMatrix, 3)
{
    Solution s;
    vector<vector<int>> matrix{{1}};
    vector<int> so = s.spiralOrder(matrix), ms{1};
    EXPECT_EQ(so, ms);
}