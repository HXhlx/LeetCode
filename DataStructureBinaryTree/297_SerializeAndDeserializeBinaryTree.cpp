#include "TreeNode.h"
#include <bits/stdc++.h>
using namespace std;
class Codec
{
    TreeNode *DFS(queue<string> &q)
    {
        if (q.empty())
            return nullptr;
        string s = q.front();
        q.pop();
        return s == "#" ? nullptr : new TreeNode(stoi(s), DFS(q), DFS(q));
    }

  public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        return root ? to_string(root->val) + " " + serialize(root->left) + serialize(root->right) : "# ";
    }
    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {
        istringstream is(data);
        queue<string> strs;
        for (string s; is >> s;)
            strs.emplace(s);
        strs.pop();
        return DFS(strs);
    }
};