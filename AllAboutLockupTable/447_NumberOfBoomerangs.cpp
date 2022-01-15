#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int numberOfBoomerangs(vector<vector<int>> &points)
    {
        int sum = 0;
        for (vector<int> &a : points)
        {
            unordered_map<size_t, int> counts;
            for (vector<int> &b : points)
                ++counts[pow(a.front() - b.front(), 2) + pow(a.back() - b.back(), 2)];
            sum += accumulate(counts.begin(), counts.end(), 0, [](int &s, pair<const size_t, int> &c)
                              { return c.second * (c.second - 1); });
        }
        return sum;
    }
};