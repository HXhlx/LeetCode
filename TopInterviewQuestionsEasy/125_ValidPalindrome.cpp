#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        for (wint_t i = 0, j = s.length() - 1; i < j; ++i, --j)
        {
            while (i < j && !isalnum(s[i]))
                ++i;
            while (i < j && !isalnum(s[j]))
                --j;
            if (i >= j)
                return true;
            if (tolower(s[i]) != tolower(s[j]))
                return false;
        }
        return true;
    }
};
TEST(ValidPalindrome, 1)
{
    Solution S;
    string s("A man, a plan, a canal: Panama");
    EXPECT_TRUE(S.isPalindrome(s));
}