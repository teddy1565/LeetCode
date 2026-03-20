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
        static int node_height(TreeNode *root, bool * current_status, int current_height) {
            if (root == nullptr || (*current_status) == false) {
                return current_height;
            }

            int left_height = node_height(root->left, current_status, current_height + 1);
            int right_height = node_height(root->right, current_status, current_height + 1);

            if (std::abs(left_height - right_height) > 1) {
                (*current_status) = false;
            }

            return std::max(left_height, right_height);
        
        }
    public:
        static bool isBalanced(TreeNode* root) {
            if (root == nullptr) {
                return true;
            }

            bool ans = true;

            node_height(root, &ans, 0);
            
            return ans;
        }
};