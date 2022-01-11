#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b)
             { return a.back() < b.back(); });
        int s = 0, e = intervals.front().back();
        for (vector<vector<int>>::iterator it = intervals.begin(); it != intervals.end(); ++it)
            if (it->front() >= e)
            {
                ++s;
                e = it->back();
            }
        return intervals.size() - s - 1;
    }
};