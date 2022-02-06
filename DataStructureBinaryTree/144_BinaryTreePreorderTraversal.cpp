#include <bits/extc++.h>
#include "TreeNode.hpp"
using namespace std;
class Solution
{
public:
    vector<int> preorderTraversal(TreeNode *root)
    {
        vector<int> preorder;
        for (TreeNode *p1 = root, *p2 = nullptr; p1; )
        {
            p2 = p1->left;
            if (p2)
            {
                while (p2->right && p2->right != p1)
                    p2 = p2->right;
                if (!p2->right)
                {
                    preorder.emplace_back(p1->val);
                    p2->right = p1;
                    p1 = p1->left;
                    continue;
                }
                else
                    p2->right = nullptr;
            }
            else
                preorder.emplace_back(p1->val);
            p1 = p1->right;
        }
        return preorder;
    }
};