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

            if (root->left != nullptr && root->right != nullptr) {
                int left = maxPathSum(root->left);      // 9
                int right = maxPathSum(root->right);    // 42

                return std::max(root->val, 
                    std::max(
                        std::max(
                            std::max(root->val + left, root->val + right),
                            root->val + left + right
                        ),
                        std::max(
                            left, right
                        )
                    )
                );
            } else if (root->left != nullptr) {
                int left = maxPathSum(root->left);      // 9

                return std::max(root->val, 
                        std::max(
                            root->val + left,
                            left
                        )
                    );
                
            } else if (root->right != nullptr) {
                int right = maxPathSum(root->right);      // 9

                return std::max(root->val, 
                        std::max(
                            root->val + right,
                            right
                        )
                    );
                
            } else {
                return root->val;
            }
        }
};