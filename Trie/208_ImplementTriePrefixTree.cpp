#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
struct Node
{
    array<shared_ptr<Node>, 26> sub_nodes{};
    bool e = false;
};
class Trie
{
    shared_ptr<Node> root = make_shared<Node>();
    shared_ptr<Node> searchPrefix(string &str)
    {
        shared_ptr<Node> node = root;
        for (char c : str)
            if (node->sub_nodes[c - 97])
                node = node->sub_nodes[c - 97];
            else
                return nullptr;
        return node;
    }

public:
    Trie() = default;
    void insert(string word)
    {
        shared_ptr<Node> node = root;
        for (char c : word)
        {
            if (!node->sub_nodes[c - 97])
                node->sub_nodes[c - 97] = make_shared<Node>();
            node = node->sub_nodes[c - 97];
        }
        node->e = true;
    }
    bool search(string word)
    {
        shared_ptr<Node> node = searchPrefix(word);
        return node != nullptr && node->e;
    }
    bool startsWith(string prefix)
    {
        return searchPrefix(prefix) != nullptr;
    }
};
TEST(ImplementTriesPrefixTree, 1)
{
    Trie trie;
    trie.insert("apple");
    EXPECT_TRUE(trie.search("apple"));
    EXPECT_FALSE(trie.search("app"));
    EXPECT_TRUE(trie.startsWith("app"));
    trie.insert("app");
    EXPECT_TRUE(trie.search("app"));
}