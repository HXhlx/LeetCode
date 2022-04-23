#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
struct Node {
    string s;
    map<char, shared_ptr<Node>> sub_nodes;
};
class Solution {
    shared_ptr<Node> root;
    string lw;
    void DFS(shared_ptr<Node> node)
    {
        for (pair<const char, shared_ptr<Node>>& sub : node->sub_nodes) {
            string& str = sub.second->s;
            if (!str.empty()) {
                if (str.length() > lw.length())
                    lw = str;
                DFS(sub.second);
            }
        }
    }

public:
    string longestWord(vector<string>& words)
    {
        root = make_shared<Node>();
        for (string& word : words) {
            shared_ptr<Node> node = root;
            for (char w : word) {
                if (node->sub_nodes.find(w) == node->sub_nodes.end())
                    node->sub_nodes[w] = make_shared<Node>();
                node = node->sub_nodes[w];
            }
            node->s = word;
        }
        DFS(root);
        return lw;
    }
};
TEST(LongestWordInDictionary, 1)
{
    Solution s;
    vector<string> words { "w", "wo", "wor", "worl", "world" };
    string s1 = "world", s2 = s.longestWord(words);
    ASSERT_EQ(s1.length(), s2.length());
    EXPECT_EQ(s1, s2);
}