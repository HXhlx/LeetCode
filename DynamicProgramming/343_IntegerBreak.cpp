#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int integerBreak(int n)
    {
        if (n <= 3)
            return n - 1;
        int q = n / 3, r = n % 3;
        switch (r)
        {
        case 0:
            return pow(3, q);
        case 1:
            return pow(3, q - 1) * 4;
        default:
            return pow(3, q) * 2;
        }
    }
};