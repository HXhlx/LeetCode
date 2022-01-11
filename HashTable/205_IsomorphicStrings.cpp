#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> sl, tl;
        for (wint_t i = 0, n = s.size(); i < n; ++i)
        {
            if (sl.find(s[i]) == sl.end())
                sl[s[i]] = t[i];
            else if (sl[s[i]] != t[i])
                return false;
            if (tl.find(t[i]) == tl.end())
                tl[t[i]] = s[i];
            else if (tl[t[i]] != s[i])
                return false;
        }
        return tl.size() == sl.size();
    }
};