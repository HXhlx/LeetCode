#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class NumMatrix
{
    vector<vector<int>> sums;

public:
    NumMatrix(vector<vector<int>> &matrix)
    {
        sums = matrix;
        for (vector<int> &sum : sums)
            partial_sum(sum.begin(), sum.end(), sum.begin());
        for (wint_t c = 0, m = matrix.size(), n = matrix[0].size(); c < n; ++c)
            for (wint_t r = 1; r < m; ++r)
                sums[r][c] += sums[r - 1][c];
    }
    int sumRegion(int row1, int col1, int row2, int col2)
    {
        int sum = sums[row2][col2];
        if (row1 && col1)
            sum -= sums[row1 - 1][col2] + sums[row2][col1 - 1] - sums[row1 - 1][col1 - 1];
        else if (row1)
            sum -= sums[row1 - 1][col2];
        else if (col1)
            sum -= sums[row2][col1 - 1];
        return sum;
    }
};
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */