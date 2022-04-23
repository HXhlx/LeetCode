#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    vector<string> letterCasePermutation(string s)
    {
        wint_t len = 0;
        vector<string> permutes;
        for (char c : s)
            if (isalpha(c))
                ++len;
        for (wint_t n = 0; n < 1 << len; ++n)
        {
            wint_t b = 0;
            string permute;
            for (char c : s)
                permute += isalpha(c) ? (n >> b++) & 1 ? toupper(c) : tolower(c) : c;
            permutes.emplace_back(permute);
        }
        return permutes;
    }
};