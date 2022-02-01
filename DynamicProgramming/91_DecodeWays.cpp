#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int numDecodings(string s)
    {
        int n = s.size(), a = 1, b = n && s.front() != '0', c = b;
        for (int i = 2; i <= n; ++i)
        {
            c = 0;
            if (s[i - 1] != '0')
                c += b;
            if (s[i - 2] != '0' && (s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)
                c += a;
            a = b;
            b = c;
        }
        return c;
    }
};