#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        auto fun = [](int &n, int &skip, string &str)
        {
            while (n >= 0)
                if (str[n] == '#')
                {
                    ++skip;
                    --n;
                }
                else if (skip)
                {
                    --skip;
                    --n;
                }
                else
                    break;
        };
        for (int skipS = 0, skipT = 0, i = s.length() - 1, j = t.length() - 1; i >= 0 || j >= 0; --i, --j)
        {
            fun(i, skipS, s);
            fun(j, skipT, t);
            if (i >= 0 && j >= 0 && s[i] != t[j] || (i < 0) ^ (j < 0))
                return false;
        }
        return true;
    }
};
TEST(BackspaceStringCompare, 1)
{
    Solution s;
    ASSERT_TRUE(s.backspaceCompare("xywrrmp", "xywrrmu#p"));
}