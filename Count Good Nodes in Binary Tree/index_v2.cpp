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

            int ans = 0;

            TreeNode *p = root;
            std::queue<TreeNode *> center_bfs_queue;
            center_bfs_queue.push(p);
            int center_max = p->val;
            while(center_bfs_queue.size() == 1) {
                TreeNode *node = center_bfs_queue.front();
                center_bfs_queue.pop();
                if (node->left != nullptr) {
                    center_bfs_queue.push(node->left);
                }
                if (node->right != nullptr) {
                    center_bfs_queue.push(node->right);
                }
                
                if (node->val >= center_max) {
                    ans += 1;
                    center_max = node->val;
                }

                p = node;
            }
            

            std::queue<TreeNode *> left_bfs_queue;
            std::queue<TreeNode *> right_bfs_queue;
            left_bfs_queue.push(p->left);
            right_bfs_queue.push(p->right);

            int left_max = center_max;
            int right_max = center_max;
            std::cout << ans << std::endl;
            std::cout << left_max << std::endl;
            std::cout << right_max << std::endl;

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