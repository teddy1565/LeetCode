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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
        static int node_height(TreeNode *root, int current_height) {
            if (root == nullptr) {
                return current_height;
            }

            return std::max(node_height(root->left, current_height + 1), node_height(root->right, current_height + 1));
        }
    public:
        static bool isBalanced(TreeNode* root) {
            if (root == nullptr) {
                return true;
            }

            int ans = std::abs(node_height(root->left, 0) - node_height(root->right, 0));
            if (ans > 1) {
                return false;
            }

            return true;
        }
};