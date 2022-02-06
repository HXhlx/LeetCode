#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        size_t m = matrix.size(), n = matrix[0].size();
        bool flag = false;
        for (size_t i = 0; i < m; ++i)
        {
            if (!matrix[i][0])
                flag = true;
            for (size_t j = 1; j < n; ++j)
                if (!matrix[i][j])
                    matrix[i][0] = matrix[0][j] = 0;
        }
        for (int i = m - 1; i >= 0; --i)
        {
            for (size_t j = 1; j < n; ++j)
                if (!(matrix[i][0] && matrix[0][j]))
                    matrix[i][j] = 0;
            if (flag)
                matrix[i][0] = 0;
        }
    }
};