#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        wint_t m = text1.size(), n = text2.size();
        vector<vector<int>> lcs(m + 1, vector<int>(n + 1));
        for (wint_t i = 0; i < m; ++i)
            for (wint_t j = 0; j < n; ++j)
                lcs[i + 1][j + 1] = text1[i] == text2[j] ? lcs[i][j] + 1 : max(lcs[i][j + 1], lcs[i + 1][j]);
        return lcs[m][n];
    }
};
TEST(LongestCommonSubsequence, 3)
{
    Solution s;
    EXPECT_EQ(s.longestCommonSubsequence("abc", "def"), 0);
}