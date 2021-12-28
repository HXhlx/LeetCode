#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
class Solution
{
    void buildSubTree(TreeNode *node, vector<int>::iterator is, vector<int>::iterator ie, vector<int>::iterator ps, vector<int>::iterator pe)
    {
        if (is != ie)
        {
            vector<int>::iterator mid = find(is, ie, *(pe - 1));
            node = new TreeNode(*mid);
            buildSubTree(node->left, is, mid, ps, ps + (mid - is));
            buildSubTree(node->right, mid + 1, ie, pe - (ie - mid), pe - 1);
        }
    }

public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
    {
        TreeNode *root;
        buildSubTree(root, inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
        return root;
    }
};