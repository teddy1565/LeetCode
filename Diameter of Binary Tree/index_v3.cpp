#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>


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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() {
        this->val = 0;
        this->left = nullptr;
        this->right = nullptr;
    }

    TreeNode(int x) {
        this->val = x;
        this->left = nullptr;
        this->right = nullptr;
    }

    TreeNode(int x, TreeNode *left, TreeNode *right) {
        this->val = x;
        this->left = left;
        this->right = right;
    }
};

int dfs(TreeNode *node, int *max) {
    if (node == nullptr) {
        return 0;
    }
    int count = 0;

    int left_count = dfs(node->left, max);
    int right_count = dfs(node->right, max);
    
    if ((*max) < left_count + right_count) {
        (*max) = left_count + right_count;
    }

    count += std::max(left_count, right_count); // O(2 * N)

    return count + 1;
}

class Solution {
    public:
        int diameterOfBinaryTree(TreeNode* root) {
            int max_size = 0;

            
            dfs(root, &max_size);

            return max_size;
        }
};