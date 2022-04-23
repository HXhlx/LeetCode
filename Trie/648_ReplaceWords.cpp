#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
struct Tree
{
    array<shared_ptr<Tree>, 26> sub_nodes{};
    string root;
};
class Solution
{
public:
    string replaceWords(vector<string> &dictionary, string sentence)
    {
        istringstream is(sentence);
        shared_ptr<Tree> root(make_shared<Tree>());
        string words, str;
        for (string &word : dictionary)
        {
            shared_ptr<Tree> node(root);
            for (char c : word)
            {
                if (!node->sub_nodes[c - 97])
                    node->sub_nodes[c - 97] = make_shared<Tree>();
                node = node->sub_nodes[c - 97];
            }
            node->root = word;
        }
        while (is >> str)
        {
            shared_ptr<Tree> node(root);
            for (string::iterator s = str.begin(); s != str.end() && node->sub_nodes[*s - 97] && node->root.empty(); ++s)
                node = node->sub_nodes[*s - 97];
            words += (node->root.empty() ? str : node->root) + " ";
        }
        words.pop_back();
        return words;
    }
};
TEST(ReplaceWords, 3)
{
    vector<string> dictionary{"a", "aa", "aaa", "aaaa"};
    Solution s;
    string sentence = "a aa a aaaa aaa aaa aaa aaaaaa bbb baba ababa";
    EXPECT_EQ(s.replaceWords(dictionary, sentence), "a a a a a a a a bbb baba a");
}