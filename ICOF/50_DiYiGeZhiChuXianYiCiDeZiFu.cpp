#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    char firstUniqChar(string s)
    {
        unordered_map<char, wint_t> t;
        for (char c : s)
            ++t[c];
        for (char c : s)
            if (t[c] == 1)
                return c;
        return ' ';
    }
};