
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
        bool is_valid_subtree(TreeNode *root, int min, int max) {
            if (root->val == 27) {
                std::cout << min << " | " << max << std::endl;
            }
            bool left_result = true;
            bool right_result = true;
            if (root->left != nullptr) {
                if (root->left->val >= root->val || root->left->val >= max) {
                    return false;
                }

                if (root->left->right != nullptr) {
                    if (root->left->right->val >= max) {
                        return false;
                    }
                }

                if (root->left->left != nullptr) {
                    if (root->left->left->val >= max) {
                        return false;
                    }
                }

                left_result = is_valid_subtree(root->left, root->left->val, min);
            }

            if (root->right != nullptr) {
                if (root->right->val <= root->val || root->right->val <= min) {
                    return false;
                }

                if (root->right->left != nullptr) {
                    if (root->right->left->val <= min) {
                        return false;
                    }
                }

                if (root->right->right != nullptr) {
                    if (root->right->right->val <= min) {
                        return false;
                    }
                }
                
                right_result = is_valid_subtree(root->right, max, root->right->val);
            }

            return left_result && right_result;
        }
    public:
        bool isValidBST(TreeNode* root) {
            return is_valid_subtree(root, root->val, root->val);
        }
};
