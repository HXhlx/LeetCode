#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
struct Node
{
    unordered_map<char, shared_ptr<Node>> subs;
    string word;
};
class Solution
{
    array<pair<short, short>, 4> direct{{{-1, 0}, {0, -1}, {1, 0}, {0, 1}}};
    bool flag;
    vector<string> common;
    wint_t m, n;
    void DFS(vector<vector<char>> &board, shared_ptr<Node> node, short r, short c)
    {
        char ch = board[r][c];
        if (ch == '#' || node->subs.find(ch) == node->subs.end())
            return;
        shared_ptr<Node> sub(node->subs[ch]);
        board[r][c] = '#';
        if (!sub->word.empty())
        {
            common.emplace_back(sub->word);
            sub->word.clear();
            flag = true;
        }
        for (pair<short, short> &d : direct)
        {
            short x = r + d.first, y = c + d.second;
            if (x >= 0 && y >= 0 && x < m && y < n)
                DFS(board, sub, x, y);
        }
        board[r][c] = ch;
        if (flag)
        {
            if (sub->subs.size())
                flag = false;
            else
                node->subs.erase(ch);
        }
    }

public:
    vector<string> findWords(vector<vector<char>> &board, vector<string> &words)
    {
        shared_ptr<Node> root(make_shared<Node>());
        m = board.size();
        n = board[0].size();
        for (string &word : words)
        {
            shared_ptr<Node> node(root);
            for (char c : word)
            {
                if (node->subs.find(c) == node->subs.end())
                    node->subs[c] = make_shared<Node>();
                node = node->subs[c];
            }
            node->word = word;
        }
        for (short r = 0; r < m; ++r)
            for (short c = 0; c < n; ++c)
                DFS(board, root, r, c);
        return common;
    }
};
TEST(WordSearch2, 1)
{
    Solution s;
    vector<vector<char>> board{{'o', 'a', 'a', 'n'}, {'e', 't', 'a', 'e'}, {'i', 'h', 'k', 'r'}, {'i', 'f', 'l', 'v'}};
    vector<string> words{"oath", "pea", "eat", "rain"}, common{"oath", "eat"}, ans = s.findWords(board, words);
    ASSERT_EQ(ans.size(), common.size());
    EXPECT_TRUE(equal(ans.begin(), ans.end(), common.begin()));
}
TEST(WordSearch2, 2)
{
    Solution s;
    vector<vector<char>> board{{'a', 'b'}, {'c', 'd'}};
    vector<string> words{"abcb"}, common, ans = s.findWords(board, words);
    ASSERT_EQ(ans.size(), common.size());
    EXPECT_TRUE(equal(ans.begin(), ans.end(), common.begin()));
}