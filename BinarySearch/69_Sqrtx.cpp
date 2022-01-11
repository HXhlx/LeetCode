#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
  public:
    int mySqrt(int x)
    {
        if (x == 0)
            return 0;
        long double x0 = x, xi = (x0 + x / x0) / 2;
        while (fabsl(xi - x0) >= 1e-5)
        {
            x0 = xi;
            xi = (x0 + x / x0) / 2;
        }
        return int(x0);
    }
};