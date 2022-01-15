#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int strStr(string haystack, string needle)
    {
        if (needle.empty())
            return 0;
        string::iterator it = search(haystack.begin(), haystack.end(), boyer_moore_horspool_searcher(needle.begin(), needle.end()));
        return it == haystack.end() ? EOF : distance(haystack.begin(), it);
    }
};