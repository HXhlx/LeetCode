#include <bits/stdc++.h>
#include <gtest/gtest.h>
#include "TreeNode.h"
using namespace std;
class Solution
{
    void build_AVL_tree(vector<int> &nums, TreeNode *&node, int low, int high)
    {
        if (low <= high)
        {
            int mid = (low + high) >> 1;
            node = new TreeNode(nums[mid]);
            build_AVL_tree(nums, node->left, low, mid - 1);
            build_AVL_tree(nums, node->right, mid + 1, high);
        }
    }

public:
    TreeNode *sortedArrayToBST(vector<int> &nums)
    {
        TreeNode *root;
        build_AVL_tree(nums, root, 0, nums.size() - 1);
        return root;
    }
};