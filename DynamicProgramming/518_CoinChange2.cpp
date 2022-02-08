#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int change(int amount, vector<int> &coins)
    {
        vector<int> c(amount + 1);
        c[0] = 1;
        for (int &coin : coins)
            for (int i = coin; i <= amount; ++i)
                c[i] += c[i - coin];
        return c[amount];
    }
};