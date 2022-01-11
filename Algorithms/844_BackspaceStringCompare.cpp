#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    bool backspaceCompare(string s, string t)
    {
        for (int skipS = 0, skipT = 0, i = s.length() - 1, j = t.length() - 1; i >= 0 || j >= 0; --i, --j)
        {
            while (i >= 0)
                if (s[i] == '#')
                {
                    ++skipS;
                    --i;
                }
                else if (skipS)
                {
                    --skipS;
                    --i;
                }
                else
                    break;
            while (j >= 0)
                if (t[j] == '#')
                {
                    ++skipT;
                    --j;
                }
                else if (skipT)
                {
                    --skipT;
                    --j;
                }
                else
                    break;
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