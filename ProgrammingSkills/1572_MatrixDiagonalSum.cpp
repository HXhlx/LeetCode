#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int diagonalSum(vector<vector<int>> &mat)
    {
        int ds = 0;
        wint_t n = mat.size();
        for (wint_t i = 0; i < n; ++i)
            ds += mat[i][i] + mat[i][n - i - 1];
        return ds - (n & 1) * mat[n >> 1][n >> 1];
    }
};