
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>
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

/**
 * @brief 
 * A valid BST is defined as follows:
 * 1. The left subtree of a node contains only nodes with keys strictly less than the node's key.
 * 2. The right subtree of a node contains only nodes with keys strictly greater than the node's key.
 * 3. Both the left and right subtrees must also be binary search trees.
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

        bool is_valid_subtree(TreeNode *root, int *min, int *max) {
            if (root == nullptr) {
                return true;
            } else if (min != nullptr && root->val <= *min) {
                return false;
            } else if (max != nullptr && root->val >= *max) {
                return false;
            }

            return is_valid_subtree(root->left, min, &root->val) && is_valid_subtree(root->right, &root->val, max);
        }
    public:
        bool isValidBST(TreeNode* root) {
            return is_valid_subtree(root, nullptr, nullptr);
        }
};
