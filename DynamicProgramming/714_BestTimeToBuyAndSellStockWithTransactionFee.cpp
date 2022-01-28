#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices, int fee)
    {
        pair<int, int> mp(0, -prices[0]);
        for_each(prices.begin() + 1, prices.end(), [&](int p)
                 { mp = {max(mp.first, mp.second + p - fee), max(mp.second, mp.first - p)}; });
        return mp.first;
    }
};