#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
using namespace __gnu_pbds;
struct Tree
{
    array<shared_ptr<Tree>, 26> sub{};
    bool End = false;
};
class Solution
{
public:
    bool wordBreak(string s, vector<string> &wordDict)
    {
        queue<wint_t> split;
        shared_ptr<Tree> root(make_shared<Tree>());
        wint_t n = s.size();
        vector<bool> visited(n + 1);
        for (string &word : wordDict)
        {
            shared_ptr<Tree> node(root);
            for (char c : word)
            {
                if (!node->sub[c - 97])
                    node->sub[c - 97] = make_shared<Tree>();
                node = node->sub[c - 97];
            }
            node->End = true;
        }
        visited[0] = true;
        split.emplace(0);
        while (!split.empty())
        {
            shared_ptr<Tree> node(root);
            for (wint_t i = split.front(); i < n && node->sub[s[i] - 97]; ++i)
            {
                node = node->sub[s[i] - 97];
                if (node->End && !visited[i + 1])
                {
                    visited[i + 1] = true;
                    split.emplace(i + 1);
                }
            }
            split.pop();
        }
        return visited.back();
    }
};
TEST(WordBreak, 1)
{
    Solution S;
    string s = "leetcode";
    vector<string> wordDict{"leet", "code"};
    EXPECT_TRUE(S.wordBreak(s, wordDict));
}
TEST(WordBreak, 2)
{
    Solution S;
    string s = "applepenapple";
    vector<string> wordDict{"apple", "pen"};
    EXPECT_TRUE(S.wordBreak(s, wordDict));
}
TEST(WordBreak, 3)
{
    Solution S;
    string s = "catsandog";
    vector<string> wordDict{"cats", "dog", "sand", "and", "cat"};
    EXPECT_FALSE(S.wordBreak(s, wordDict));
}