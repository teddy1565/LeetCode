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

int dfs(TreeNode *node) {
    if (node == nullptr) {
        return 0;
    }
    int count = 0;

    count += std::max(dfs(node->left), dfs(node->right));

    return count + 1;
}

class Solution {
    public:
        int diameterOfBinaryTree(TreeNode* root) {
            int max_size = 0;
            std::queue<TreeNode *> node_list;
            node_list.push(root);

            while(node_list.size() > 0) {
                
                TreeNode *node = node_list.front();
                node_list.pop();

                if (node == nullptr) {
                    continue;
                }
                int node_length = dfs(node->left) + dfs(node->right);
                max_size = std::max(node_length, max_size);
                std::cout << node_length << std::endl;
                
                node_list.push(node->left);
                node_list.push(node->right);
            }

            return max_size;
        }
};