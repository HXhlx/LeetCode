#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    string reverseVowels(string s)
    {
        bitset<128> ascii;
        for (char c : "aeiouAEIOU")
            ascii.set(c);
        for (unsigned l = 0, r = s.length() - 1; l < r; ++l)
            if (ascii[s[l]])
            {
                while (!ascii[s[r]] && r > l)
                    --r;
                if (r > l)
                    swap(s[r--], s[l]);
            }
        return s;
    }
};
TEST(ReverseVowelsOfAString, 1)
{
    Solution s;
    EXPECT_EQ(s.reverseVowels("leetcode"), "leotcede");
}