#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() {
        this->val = 0;
        this->left = nullptr;
        this->right = nullptr;
    };

    TreeNode(int x) {
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    };

    TreeNode(int x, TreeNode *left, TreeNode *right) {
        this->val = x;
        this->left = left;
        this->right = right;
    };
};

static int dfs(TreeNode *node, int max, int i) {
    if (node == nullptr) {
        return i - 1;
    }

    if (node->left != nullptr) {
        if (node->left->val >= max) {
            i = dfs(node->left, node->left->val, i + 1);
        } else {
            i = dfs(node->left, max, i);
        }
    }
    if (node->right != nullptr) {
        if (node->right->val >= max) {
            i = dfs(node->right, node->right->val, i + 1);
        } else {
            i = dfs(node->right, max, i);
        }
    }

    return i;
}
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
        
        

    public:
        int goodNodes(TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }
            return dfs(root, root->val, 1);
        }
};