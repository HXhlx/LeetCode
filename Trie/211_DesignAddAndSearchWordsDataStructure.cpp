#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
struct Dictionary
{
    unordered_map<char, shared_ptr<Dictionary>> words;
    bool End = false;
};
class WordDictionary
{
    shared_ptr<Dictionary> root = make_shared<Dictionary>();
    bool DFS(shared_ptr<Dictionary> node, string::iterator s, string::iterator e)
    {
        if (s == e)
            return node->End;
        if (*s == '.')
            return node->words.empty() ? false : accumulate(node->words.begin(), node->words.end(), false, [this, s, e](bool f, const pair<char, shared_ptr<Dictionary>> sub_node)
                                                            { return f || this->DFS(sub_node.second, s + 1, e); });
        return node->words.find(*s) == node->words.end() ? false : DFS(node->words[*s], s + 1, e);
    }

public:
    WordDictionary() = default;
    void addWord(string word)
    {
        shared_ptr<Dictionary> node(root);
        for (char c : word)
        {
            if (node->words.find(c) == node->words.end())
                node->words[c] = make_shared<Dictionary>();
            node = node->words[c];
        }
        node->End = true;
    }
    bool search(string word)
    {
        return DFS(root, word.begin(), word.end());
    }
};