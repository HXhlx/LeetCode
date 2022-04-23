#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    string smallestGoodBase(string n)
    {
        size_t sgb = stoull(n), mm = floor(log2(sgb));
        for (size_t m = mm; m; --m)
        {
            size_t k = pow(sgb, 1. / m), mul = 1, sum = 1;
            for (size_t i = 0; i < m; ++i)
            {
                mul *= k;
                sum += mul;
            }
            if (sum == sgb)
                return to_string(k);
        }
        return to_string(sgb - 1);
    }
};