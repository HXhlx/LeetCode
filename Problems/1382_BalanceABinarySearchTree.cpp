#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "TreeNode.hpp"
using namespace std;
class Solution {
    vector<int> bst;
    void Inorder(TreeNode* node)
    {
        if (node) {
            Inorder(node->left);
            bst.emplace_back(node->val);
            Inorder(node->right);
        }
    }
    TreeNode* build_AVL(wint_t low, wint_t high)
    {
        TreeNode* node = nullptr;
        if (low < high) {
            wint_t mid = (low + high) >> 1;
            node = new TreeNode(bst[mid], build_AVL(low, mid), build_AVL(mid + 1, high));
        }
        return node;
    }

public:
    TreeNode* balanceBST(TreeNode* root)
    {
        Inorder(root);
        return build_AVL(0, bst.size());
    }
};