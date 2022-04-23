#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    bool judgeSquareSum(int c)
    {
        for (unsigned a = 2; a * a <= c; ++a)
            if (c % a == 0)
            {
                unsigned e = 0;
                while (c % a == 0)
                {
                    c /= a;
                    ++e;
                }
                if (a % 4 == 3 && e % 2)
                    return false;
            }
        return c % 4 != 3;
    }
};