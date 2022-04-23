#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    string frequencySort(string s)
    {
        wint_t m = 0;
        unordered_map<char, wint_t> fre;
        for (char c : s)
            m = max(m, ++fre[c]);
        string strs[m + 1], str;
        for (auto [c, w] : fre)
            strs[w] += c;
        for (wint_t i = m; i; --i)
            for (char c : strs[i])
                str += string(i, c);
        return str;
    }
};