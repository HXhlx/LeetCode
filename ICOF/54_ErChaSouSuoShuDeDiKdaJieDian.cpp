#include "TreeNode.hpp"
#include <bits/extc++.h>
#include <gtest/gtest.h>
using namespace std;
class Solution {
    vector<int> kl;
    void Inorder(TreeNode* node, int k)
    {
        if (node) {
            Inorder(node->right, k);
            if (kl.size() >= k)
                return;
            kl.emplace_back(node->val);
            Inorder(node->left, k);
        }
    }

public:
    int kthLargest(TreeNode* root, int k)
    {
        Inorder(root, k);
        return kl.back();
    }
};