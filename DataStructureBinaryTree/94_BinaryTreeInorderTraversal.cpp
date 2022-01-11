#include <bits/stdc++.h>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
    vector<int> inorderTraversal(TreeNode *root)
    {
        vector<int> inorder;
        for (TreeNode *predecessor = nullptr; root;)
            if (root->left)
            {
                predecessor = root->left;
                while (predecessor->right && predecessor->right != root)
                    predecessor = predecessor->right;
                if (predecessor->right)
                {
                    inorder.emplace_back(root->val);
                    predecessor->right = nullptr;
                    root = root->right;
                }
                else
                {
                    predecessor->right = root;
                    root = root->left;
                }
            }
            else
            {
                inorder.emplace_back(root->val);
                root = root->right;
            }
        return inorder;
    }
};