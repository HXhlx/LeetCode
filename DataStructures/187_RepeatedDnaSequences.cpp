#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    vector<string> findRepeatedDnaSequences(string s)
    {
        vector<string> frds;
        if (s.length() <= 10)
            return frds;
        unordered_map<char, wint_t> links{{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        unordered_map<unsigned, unsigned> visited;
        unsigned b = 0;
        for (wint_t i = 0; i < 9; ++i)
            b = (b << 2) | links[s[i]];
        for (wint_t i = 9, n = s.length(); i < n; ++i)
        {
            b = ((b << 2) | links[s[i]]) & ((1 << 20) - 1);
            if (++visited[b] == 2)
                frds.emplace_back(s.substr(i - 9, 10));
        }
        return frds;
    }
};