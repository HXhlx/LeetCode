#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
  public:
    vector<vector<int>> merge(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> m{intervals.front()};
        for (vector<int> &vals : intervals)
            if (m.back()[1] >= vals[0])
                m.back()[1] = max(vals[1], m.back()[1]);
            else
                m.emplace_back(vals);
        return m;
    }
};