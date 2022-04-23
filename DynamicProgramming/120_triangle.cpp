#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        vector<int> minimum(triangle.back());
        for (int i = triangle.size() - 2; i >= 0; --i)
            for (int j = 0; j <= i; ++j)
                minimum[j] = min(minimum[j], minimum[j + 1]) + triangle[i][j];
        return minimum[0];
    }
};