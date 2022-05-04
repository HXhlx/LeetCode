#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>> &points, int k)
    {
        nth_element(points.begin(), points.begin() + k, points.end(), [](vector<int> &a, vector<int> &b)
                    { return a.front() * a.front() + a.back() * a.back() < b.front() * b.front() + b.back() * b.back(); });
        return vector<vector<int>>(points.begin(), points.begin() + k);
    }
};