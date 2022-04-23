#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution
{
public:
    int longestPalindrome(string s)
    {
        int ans = 0;
        unordered_map<char, int> cs;
        for (char c : s)
            ++cs[c];
        for (pair<char, int> c : cs)
        {
            ans += c.second >> 1 << 1;
            if (c.second % 2 && ans % 2 == 0)
                ++ans;
        }
        return ans;
    }
};