#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int longestPalindromeSubseq(string s)
    {
        wint_t n = s.length();
        vector<vector<wint_t>> lps(n, vector<wint_t>(n));
        for (short i = n - 1; i >= 0; --i)
        {
            lps[i][i] = 1;
            for (wint_t j = i + 1; j < n; ++j)
                lps[i][j] = s[i] == s[j] ? lps[i + 1][j - 1] + 2 : max(lps[i + 1][j], lps[i][j - 1]);
        }
        return lps[0][n - 1];
    }
};