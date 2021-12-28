#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int len = 0;
        while (n)
        {
            n &= n - 1;
            ++len;
        }
        return len;
    }
};