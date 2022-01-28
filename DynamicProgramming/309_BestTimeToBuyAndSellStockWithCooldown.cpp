#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int mp0 = -prices[0], mp1 = 0, mp2 = 0;
        for_each(prices.begin() + 1, prices.end(), [&](int &p)
                 {
                     int m0 = max(mp0, mp2 - p), m1 = mp0 + p, m2 = max(mp1, mp2);
                     mp0 = m0;
                     mp1 = m1;
                     mp2 = m2;
                 });
        return max(mp1, mp2);
    }
};