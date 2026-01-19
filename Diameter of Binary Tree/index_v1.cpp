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

class Solution {
    public:
        int diameterOfBinaryTree(TreeNode* root) {
            std::queue<TreeNode *> bfs_queue;
            std::queue<int> num_queue;
            bfs_queue.push(root);
            num_queue.push(0);

            int max_num = 0;
            TreeNode *deep_node = root;

            while(bfs_queue.size() > 0) {
                TreeNode *node = bfs_queue.front();
                bfs_queue.pop();
                int i = num_queue.front();
                num_queue.pop();

                if (i >= max_num) {
                    deep_node = node;
                }

                if (node->left != nullptr) {
                    bfs_queue.push(node->left);
                    num_queue.push(i + 1);
                    
                    max_num = i + 1;
                }
                if (node->right != nullptr) {
                    bfs_queue.push(node->right);
                    num_queue.push(i + 1);
                    max_num = i + 1;
                }
            }

            bfs_queue.push(deep_node);
            max_num = 0;

            while(bfs_queue.size() > 0) {
                TreeNode *node = bfs_queue.front();
                bfs_queue.pop();
                int i = num_queue.front();
                num_queue.pop();

                if (i >= max_num) {
                    deep_node = node;
                    max_num = i;
                }

                if (node->left != nullptr) {
                    bfs_queue.push(node->left);
                    num_queue.push(i + 1);
                }
                if (node->right != nullptr) {
                    bfs_queue.push(node->right);
                    num_queue.push(i + 1);
                }
            }
            
            return max_num;
        }
};