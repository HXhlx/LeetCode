#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        int m = needle.size(), n = haystack.size();
        if (m == 0)
            return 0;
        vector<int> pi(m);
        for (int i = 1, j = 0; i < m; ++i)
        {
            while (j > 0 && needle[i] != needle[j])
                j = pi[j - 1];
            if (needle[i] == needle[j])
                ++j;
            pi[i] = j;
        }
        for (int i = 0, j = 0; i < n; ++i)
        {
            while (j > 0 && haystack[i] != needle[j])
                j = pi[j - 1];
            if (haystack[i] == needle[j])
                ++j;
            if (j == m)
                return i - m + 1;
        }
        return EOF;
    }
};