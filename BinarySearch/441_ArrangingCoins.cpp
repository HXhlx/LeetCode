#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int arrangeCoins(int n)
    {
        return (sqrt((static_cast<size_t>(n) << 3) + 1) - 1) / 2;
    }
};