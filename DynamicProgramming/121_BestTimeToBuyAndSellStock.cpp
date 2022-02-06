#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        int maxprofit = 0, minprice = INT_MAX;
        for (int &price : prices)
        {
            maxprofit = max(maxprofit, price - minprice);
            minprice = min(minprice, price);
        }
        return maxprofit;
    }
};