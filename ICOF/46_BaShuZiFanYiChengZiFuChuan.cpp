#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int translateNum(int num)
    {
        pair<int, int> dp(1, 1);
        for (long n = 10; n <= num; n *= 10)
        {
            int p = num / (n / 10) % 100;
            dp = {dp.second, dp.second + (p < 26 && p >= 10) * dp.first};
        }
        return dp.second;
    }
};