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
#include <array>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    private:
        static int max_path_sum_helper(TreeNode *root, int *res) {
            if (root == nullptr) {
                return 0;
            }

            int left = std::max(max_path_sum_helper(root->left, res), 0);
            int right = std::max(max_path_sum_helper(root->right, res), 0);
            
            // record sub tree max
            (*res) = std::max((*res), left + right + root->val);
            return std::max(left, right) + root->val;
        }
    public:
        int maxPathSum(TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }
            
            int res = INT_MIN;

            return std::max(max_path_sum_helper(root, &res), res);
        }
};