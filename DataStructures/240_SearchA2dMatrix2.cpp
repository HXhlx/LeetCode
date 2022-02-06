#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int m = matrix.size(), n = matrix[0].size(), x = 0, y = n - 1;
        while (x < m && y >= 0)
            if (matrix[x][y] > target)
                --y;
            else if (matrix[x][y] < target)
                ++x;
            else
                return true;
        return false;
    }
};