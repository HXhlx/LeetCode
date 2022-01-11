#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    vector<int> findAnagrams(string s, string p)
    {
        array<int, 26> abc{};
        int s_n = s.size(), p_n = p.size();
        vector<int> num;
        if (s_n < p_n)
            return {};
        for (int i = 0; i < p_n; ++i)
        {
            --abc[p[i] - 'a'];
            ++abc[s[i] - 'a'];
        }
        int diff = count_if(abc.begin(), abc.end(), [](int a)
                            { return a != 0; });
        if (!diff)
            num.emplace_back(0);
        for (int i = p_n; i < s_n; ++i)
        {
            switch (abc[s[i - p_n] - 'a']--)
            {
            case 0:
                ++diff;
                break;
            case 1:
                --diff;
                break;
            }
            switch (abc[s[i] - 'a']++)
            {
            case -1:
                --diff;
                break;
            case 0:
                ++diff;
                break;
            }
            if (!diff)
                num.emplace_back(i - p_n + 1);
        }
        return num;
    }
};
TEST(FindAllAnagramsInAString, 1)
{
    Solution s;
    vector<int> ret{0, 6}, num = s.findAnagrams("cbaebabacd", "abc");
    ASSERT_EQ(num.size(), ret.size());
    for (int i = 0; i < ret.size(); ++i)
        EXPECT_EQ(ret[i], num[i]);
}
TEST(FindAllAnagramsInAString, 2)
{
    Solution s;
    vector<int> ret{0, 1, 2}, num = s.findAnagrams("abab", "ab");
    ASSERT_EQ(num.size(), ret.size());
    for (int i = 0; i < ret.size(); ++i)
        EXPECT_EQ(ret[i], num[i]);
}