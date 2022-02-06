#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
  public:
    bool isPerfectSquare(int num)
    {
        long double x0 = num, xi = (x0 + num / x0) / 2;
        while (fabsl(xi - x0) >= 1e-5)
        {
            x0 = xi;
            xi = (x0 + num / x0) / 2;
        }
        int x = int(x0);
        return x * x == num;
    }
};