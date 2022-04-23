#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        size_t num = 1;
        pair<int, int> mm = minmax(m, n);
        mm.second += mm.first - 1;
        for (size_t i = 1; i < mm.first; ++i)
            num = num * (mm.second - i) / i;
        return num;
    }
};