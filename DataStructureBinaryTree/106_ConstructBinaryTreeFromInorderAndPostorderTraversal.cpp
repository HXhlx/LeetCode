#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
class Solution
{
    TreeNode *buildSubTree(vector<int>::iterator is, vector<int>::iterator ie, vector<int>::iterator ps, vector<int>::iterator pe)
    {
        if (is != ie)
        {
            vector<int>::iterator mid = find(is, ie, *(pe - 1));
            return new TreeNode(*mid, buildSubTree(is, mid, ps, ps + distance(is, mid)), buildSubTree(mid + 1, ie, ps + distance(is, mid), pe - 1));
        }
        else
            return nullptr;
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        return buildSubTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
};