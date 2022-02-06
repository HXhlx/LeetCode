#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        int a = cost[0], b = cost[1], n = cost.size();
        for (int i = 2; i < n; ++i)
        {
            int temp = min(a + cost[i], b + cost[i]);
            a = b;
            b = temp;
        }
        return min(a, b);
    }
};