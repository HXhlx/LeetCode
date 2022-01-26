#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
    array<array<size_t, 2>, 2> multiply(array<array<size_t, 2>, 2> &a, array<array<size_t, 2>, 2> &b)
    {
        array<array<size_t, 2>, 2> c;
        for (wint_t i = 0; i < 2; ++i)
            for (wint_t j = 0; j < 2; ++j)
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
        return c;
    }

public:
    int climbStairs(int n)
    {
        array<array<size_t, 2>, 2> mat{{{1, 1}, {1, 0}}}, ret{{{1, 0}, {0, 1}}};
        while (n)
        {
            if (n & 1)
                ret = multiply(ret, mat);
            n >>= 1;
            mat = multiply(mat, mat);
        }
        return ret[0][0];
    }
};