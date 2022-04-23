#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>> &firstList, vector<vector<int>> &secondList)
    {
        vector<vector<int>> interval;
        for (vector<vector<int>>::iterator first = firstList.begin(), second = secondList.begin(); first != firstList.end() && second != secondList.end();)
        {
            int low = max(first->front(), second->front()), high = min(first->back(), second->back());
            if (low <= high)
                interval.push_back({low, high});
            if (first->back() < second->back())
                ++first;
            else
                ++second;
        }
        return interval;
    }
};