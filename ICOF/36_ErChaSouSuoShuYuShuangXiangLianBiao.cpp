#include "Node.hpp"
#include <bits/extc++.h>
#include "gtest/gtest.h"
using namespace std;
class Solution {
public:
    Node* treeToDoublyList(Node* root)
    {
        if (!root)
            return root;
        Node* node = root;
        while (node->left)
            node = node->left;
        Node* ttdl = node;
        for (node = nullptr; root;)
            if (root->left) {
                node = root->left;
                while (node->right && node->right != root)
                    node = node->right;
                if (node->right)
                    root = root->right;
                else {
                    node->right = root;
                    root = root->left;
                }
            } else
                root = root->right;
        for (node = ttdl; node->right; node = node->right)
            node->right->left = node;
        return ttdl;
    }
};