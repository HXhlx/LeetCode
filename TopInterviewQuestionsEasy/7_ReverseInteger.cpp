#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int reverse(int x)
    {
        int y = 0, m = INT_MAX / 10;
        while (x)
        {
            if (abs(y) > m)
                return 0;
            y = y * 10 + x % 10;
            x /= 10;
        }
        return y;
    }
};