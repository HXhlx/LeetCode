#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
struct Tree
{
    array<shared_ptr<Tree>, 26> sub_nodes{};
    bool End = false;
    int val;
    Tree(int v = 0) : val(v) {}
};
class MapSum
{
    shared_ptr<Tree> root = make_shared<Tree>();

public:
    MapSum() = default;
    void insert(string key, int val)
    {
        shared_ptr<Tree> node = root;
        bool e = true;
        for (char c : key)
            if (node->sub_nodes[c - 97])
                node = node->sub_nodes[c - 97];
            else
            {
                e = false;
                break;
            }
        if (node->End && e)
            val += accumulate(node->sub_nodes.begin(), node->sub_nodes.end(), 0, [](int v, shared_ptr<Tree> sub_node)
                              { return v + (sub_node ? sub_node->val : 0); }) -
                   node->val;
        node = root;
        for (char c : key)
        {
            if (node->sub_nodes[c - 97])
                node->sub_nodes[c - 97]->val += val;
            else
                node->sub_nodes[c - 97] = make_shared<Tree>(val);
            node = node->sub_nodes[c - 97];
        }
        node->End = true;
    }
    int sum(string prefix)
    {
        shared_ptr<Tree> node = root;
        for (char c : prefix)
            if (node->sub_nodes[c - 97])
                node = node->sub_nodes[c - 97];
            else
                return 0;
        return node->val;
    }
};