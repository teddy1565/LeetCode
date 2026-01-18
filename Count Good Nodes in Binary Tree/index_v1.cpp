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

            int ans = 1;

            std::queue<TreeNode *> left_bfs_queue;
            std::queue<TreeNode *> right_bfs_queue;
            left_bfs_queue.push(root->left);
            right_bfs_queue.push(root->right);

            int left_max = root->val;
            int right_max = root->val;

            while(left_bfs_queue.size() > 0) {
                TreeNode *node = left_bfs_queue.front();
                left_bfs_queue.pop();
                
                if (node == nullptr) {
                    continue;
                }

                if (node->val >= left_max) {
                    ans += 1;
                    left_max = node->val;
                }

                left_bfs_queue.push(node->left);
                left_bfs_queue.push(node->right);
            }

            while(right_bfs_queue.size() > 0) {
                TreeNode *node = right_bfs_queue.front();
                right_bfs_queue.pop();
                
                if (node == nullptr) {
                    continue;
                }

                if (node->val >= right_max) {
                    ans += 1;
                    right_max = node->val;
                }

                right_bfs_queue.push(node->left);
                right_bfs_queue.push(node->right);
            }

            return ans;
        }
};