#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
    set<int> cycle{4, 16, 20, 37, 42, 58, 89, 145};
    int get_next(int n)
    {
        int s = 0;
        while (n)
        {
            s += pow(n % 10, 2);
            n /= 10;
        }
        return s;
    }

public:
    bool isHappy(int n)
    {
        while (n != 1 && cycle.find(n) == cycle.end())
            n = get_next(n);
        return n == 1;
    }
};