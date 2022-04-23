#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int maxlen = 0;
        unordered_map<char, int> strs;
        for (int start = 0, end = 0; end < s.size(); ++end)
        {
            if (strs.find(s[end]) != strs.end())
                start = max(strs[s[end]] + 1, start);
            maxlen = max(maxlen, end - start + 1);
            strs[s[end]] = end;
        }
        return maxlen;
    }
};