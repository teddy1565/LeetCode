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
    public:
        int maxPathSum(TreeNode* root) {
            if (root == nullptr) {
                return 0;
            }

            int a = root->val;
            int left = maxPathSum(root->left);
            int right = maxPathSum(root->right);
            int b = root->val + left;
            int c = root->val + right;
            int d = root->val + left + right;

            return std::max(a, std::max(d, std::max(std::max(b, c), std::max(left, right))));
        }
};