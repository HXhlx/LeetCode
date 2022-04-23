#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        vector<int> cc(amount + 1, amount + 1);
        cc[0] = 0;
        for (wint_t i = 1, n = coins.size(); i <= amount; ++i)
            for (wint_t j = 0; j < n; ++j)
                if (coins[j] <= i)
                    cc[i] = min(cc[i], cc[i - coins[j]] + 1);
        return cc[amount] > amount ? EOF : cc[amount];
    }
};