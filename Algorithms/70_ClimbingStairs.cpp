#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
    vector<vector<ssize_t>> multiply(vector<vector<ssize_t>> &a, vector<vector<ssize_t>> &b)
    {
        vector<vector<ssize_t>> c(2, vector<ssize_t>(2));
        for (wint_t i = 0; i < 2; ++i)
            for (wint_t j = 0; j < 2; ++j)
                c[i][j] = a[i][0] * b[0][j] + a[i][1] * b[1][j];
        return c;
    }

public:
    int climbStairs(int n)
    {
        vector<vector<ssize_t>> mat{{1, 1}, {1, 0}}, ret{{1, 0}, {0, 1}};
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