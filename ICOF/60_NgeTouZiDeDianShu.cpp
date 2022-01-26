#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<double> dicesProbability(int n)
    {
        vector<double> dp(6, 1. / 6);
        for (wint_t i = 2; i <= n; ++i)
        {
            vector<double> tmp(5 * i + 1);
            for (wint_t j = 0, n = dp.size(); j < n; ++j)
                for (wint_t k = 0; k < 6; ++k)
                    tmp[j + k] += dp[j] / 6;
            dp = tmp;
        }
        return dp;
    }
};