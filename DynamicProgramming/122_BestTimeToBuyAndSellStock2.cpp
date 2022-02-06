#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mp = 0;
        if (prices.empty())
            return mp;
        for (vector<int>::iterator it = prices.begin() + 1; it != prices.end(); ++it)
            mp += max(0, *it - *(it - 1));
        return mp;
    }
};