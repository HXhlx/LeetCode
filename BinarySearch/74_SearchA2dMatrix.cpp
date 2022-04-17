#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        vector<vector<int>>::iterator row = upper_bound(matrix.begin(), matrix.end(), target, [](int t, vector<int> &vec)
                                                        { return t < vec.front(); });
        if (row == matrix.begin())
            return false;
        return binary_search((row - 1)->begin(), (row - 1)->end(), target);
    }
};