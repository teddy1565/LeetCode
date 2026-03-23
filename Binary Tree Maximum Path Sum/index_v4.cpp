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
        
        static int max_path_sum_helper(TreeNode *root) {
            if (root == nullptr) {
                return 0;
            }

            int left = max_path_sum_helper(root->left);
            int right = max_path_sum_helper(root->right);


            int current_max = root->val + left + right;

            if (root->left != nullptr) {
                // current_max = std::max(current_max, left);
                current_max = std::max(current_max, std::max(left, root->val + left));
            }

            if (root->right != nullptr) {
                // current_max = std::max(current_max, right);
                current_max = std::max(current_max, std::max(right, root->val + right));
            }

        
            return current_max;
        }

    public:
        int maxPathSum(TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }

            return max_path_sum_helper(root);
        }
};