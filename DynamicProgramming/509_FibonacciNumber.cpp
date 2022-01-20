#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int fib(int n)
    {
        if (n <= 1)
            return n;
        pair<int, int> f(0, 1);
        for (int i = 2; i <= n; ++i)
            f = {f.second, f.first + f.second};
        return f.second;
    }
};