#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    bool areAlmostEqual(string s1, string s2)
    {
        vector<pair<char, char>> aae;
        for (wint_t i = 0, n = s1.length(); i < n; ++i)
            if (s1[i] != s2[i])
            {
                aae.emplace_back(s1[i], s2[i]);
                if (aae.size() > 2)
                    return false;
            }
        return aae.size() == 2 && aae[0].first == aae[1].second && aae[0].second == aae[1].first || aae.size() == 0;
    }
};