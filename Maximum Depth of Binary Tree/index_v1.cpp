#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>

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

        int node_traval(TreeNode *root, int n) {
            if (root == nullptr) {
                return n - 1;
            }

            int x = node_traval(root->left, n + 1);
            int y = node_traval(root->right, n + 1);

            return std::max(x, y);
        }

    public:

        /**
         * @brief 
         * 
         * Given the root of a binary tree, return its maximum depth.

            A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
         * 
         * @param root 
         * @return int 
         */
        int maxDepth(TreeNode* root) {
            return node_traval(root, 1);
        }
};