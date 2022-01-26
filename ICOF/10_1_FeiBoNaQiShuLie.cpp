#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int fib(int n)
    {
        pair<unsigned, unsigned> f(0, 1);
        for (int i = 0; i < n; ++i)
            f = {f.second, (f.first + f.second) % 1000000007};
        return f.first;
    }
};