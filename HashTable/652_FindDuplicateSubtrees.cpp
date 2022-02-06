#include <bits/extc++.h>
#include <gtest/gtest.h>
#include "TreeNode.hpp"
using namespace std;
class Solution
{
    wint_t t;
    unordered_map<string, wint_t> trees;
    unordered_map<wint_t,wint_t>c;
    vector<TreeNode *> ans;
    wint_t lookup(TreeNode*node){
        if(node==nullptr)
            return 0;
        string serial = to_string(node->val) + "," + to_string(lookup(node->left)) + "," + to_string(lookup(node->right));
    }

public:
    vector<TreeNode *> findDuplicateSubtrees(TreeNode *root)
    {
    }
};