#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int numSquares(int n)
    {
        int s = sqrt(n), t = n;
        if (s * s == n)
            return 1;
        while (t % 4 == 0)
            t /= 4;
        if (t % 8 == 7)
            return 4;
        for (int i = 1; i <= s; ++i)
        {
            int j = n - i * i, sj = sqrt(j);
            if (sj * sj == j)
                return 2;
        }
        return 3;
    }
};