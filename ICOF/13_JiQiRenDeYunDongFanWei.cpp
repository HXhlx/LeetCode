#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
    wint_t digit_sum(wint_t r, wint_t c)
    {
        wint_t s = 0;
        while (r)
        {
            s += r % 10;
            r /= 10;
        }
        while (c)
        {
            s += c % 10;
            c /= 10;
        }
        return s;
    }

public:
    int movingCount(int m, int n, int k)
    {
        wint_t mc = 0, board = k >= 8 ? (k - 7) * 10 : k + 1;
        for (wint_t r = 0; r < m; ++r)
            for (wint_t c = 0; c < n && r + c < board; ++c)
                if (digit_sum(r, c) <= k)
                    ++mc;
        return mc;
    }
};