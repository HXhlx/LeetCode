#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points)
    {
        int d = EOF, s = INT_MAX;
        for (wint_t i = 0, n = points.size(); i < n; ++i)
            if (points[i][0] == x || points[i][1] == y)
            {
                int l = abs(points[i][0] - x) + abs(points[i][1] - y);
                if (s > l)
                {
                    d = i;
                    s = l;
                }
            }
        return d;
    }
};