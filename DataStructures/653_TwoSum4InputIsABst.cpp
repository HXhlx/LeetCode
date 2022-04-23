#include <bits/extc++.h>
#include "gtest/gtest.h"
#include "TreeNode.hpp"
using namespace std;
class Solution
{
    vector<int> nodes;
    void inorder(TreeNode *root)
    {
        if (root)
        {
            inorder(root->left);
            nodes.emplace_back(root->val);
            inorder(root->right);
        }
    }

public:
    bool findTarget(TreeNode *root, int k)
    {
        inorder(root);
        for (int low = 0, high = nodes.size() - 1, mid; low < high;)
        {
            mid = (low + high) / 2;
            if (nodes[low] + nodes[mid + 1] == k || nodes[low] + nodes[high] == k || nodes[mid] + nodes[high] == k)
                return true;
            if (nodes[low] + nodes[mid + 1] > k)
                high = mid;
            else if (nodes[high] + nodes[mid] < k)
                low = mid + 1;
            else
                nodes[low] + nodes[high] > k ? --high : ++low;
        }
        return false;
    }
};