#include <bits/stdc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution
{
public:
    bool wordPattern(string pattern, string s)
    {
        array<string, 26> link;
        string str;
        string::iterator p = pattern.begin();
        unordered_map<string, char> rlink;
        for (istringstream strs(s); strs >> str; ++p)
        {
            if (p == pattern.end())
                return false;
            int i = *p - 'a';
            if (!link[i].empty() && link[i] != str || rlink.count(str) && rlink[str] != *p)
                return false;
            link[i] = str;
            rlink[str] = *p;
        }
        return p == pattern.end();
    }
};
TEST(WordPattern, 1)
{
    Solution s;
    EXPECT_TRUE(s.wordPattern("abba", "dog cat cat dog"));
}
TEST(WordPattern, 2)
{
    Solution s;
    EXPECT_FALSE(s.wordPattern("abba", "dog cat cat fish"));
}
TEST(WordPattern, 3)
{
    Solution s;
    EXPECT_FALSE(s.wordPattern("aaaa", "dog cat cat dog"));
}
TEST(WordPattern, 4)
{
    Solution s;
    EXPECT_FALSE(s.wordPattern("abba", "dog dog dog dog"));
}