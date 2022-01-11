#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        int a = s1.size(), b = s2.size();
        if (a > b)
            return false;
        array<int, 26> abc{};
        for (int i = 0; i < a; ++i)
        {
            --abc[s1[i] - 'a'];
            ++abc[s2[i] - 'a'];
        }
        int diff = 0;
        for (int n : abc)
            if (n)
                ++diff;
        if (diff == 0)
            return true;
        for (int i = a; i < b; ++i)
        {
            int x = s2[i] - 'a', y = s2[i - a] - 'a';
            if (x == y)
                continue;
            if (abc[x] == 0)
                ++diff;
            ++abc[x];
            if (abc[x] == 0)
                --diff;
            if (abc[y] == 0)
                ++diff;
            --abc[y];
            if (abc[y] == 0)
                --diff;
            if (diff == 0)
                return true;
        }
        return false;
    }
};
TEST(PermutationInString,1){
    Solution s;
    EXPECT_TRUE(s.checkInclusion("ab", "eidbaooo"));
}