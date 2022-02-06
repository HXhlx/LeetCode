#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int tribonacci(int n)
    {
        if (n <= 2)
            return ceil(double(n) / 2);
        tuple<int, int, int> fib(0, 1, 1);
        for (int i = 3; i <= n; ++i)
            fib = {get<1>(fib), get<2>(fib), get<0>(fib) + get<1>(fib) + get<2>(fib)};
        return get<2>(fib);
    }
};