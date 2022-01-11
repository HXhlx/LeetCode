#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
class Solution
{
    TreeNode *buildSubTree(vector<int>::iterator is, vector<int>::iterator ie, vector<int>::iterator ps, vector<int>::iterator pe)
    {
        if (is != ie)
        {
            vector<int>::iterator mid = find(is, ie, *ps);
            return new TreeNode(*mid, buildSubTree(is, mid, ps + 1, ps + distance(is, mid) + 1), buildSubTree(mid + 1, ie, ps + distance(is, mid) + 1, pe));
        }
        else
            return nullptr;
    }

public:
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
    {
        return buildSubTree(inorder.begin(), inorder.end(), preorder.begin(), preorder.end());
    }
};