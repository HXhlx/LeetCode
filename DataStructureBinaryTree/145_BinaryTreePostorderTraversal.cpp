#include <bits/extc++.h>
#include "TreeNode.hpp"
using namespace std;
class Solution
{
    vector<int> postorder;
    void addPath(TreeNode *node)
    {
        size_t c = 0;
        while (node)
        {
            postorder.emplace_back(node->val);
            node = node->right;
            ++c;
        }
        reverse(postorder.end() - c, postorder.end());
    }

public:
    vector<int> postorderTraversal(TreeNode *root)
    {
        for (TreeNode *p1 = root, *p2 = nullptr; p1;)
        {
            p2 = p1->left;
            if (p2)
            {
                while (p2->right && p2->right != p1)
                    p2 = p2->right;
                if (p2->right)
                {
                    p2->right = nullptr;
                    addPath(p1->left);
                }
                else
                {
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                }
            }
            p1 = p1->right;
        }
        addPath(root);
        return postorder;
    }
};