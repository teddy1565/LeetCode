#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>

class Solution {
    private:
        struct TreeNode {
            int val;
            TreeNode *left;
            TreeNode *right;
            TreeNode() : val(0), left(nullptr), right(nullptr) {}
            TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
            TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
        };

        bool dfs(TreeNode *node, TreeNode *sub_node) {
            if (node == nullptr && sub_node == nullptr) {
                return true;
            } else if (node == nullptr || sub_node == nullptr) {
                return false;
            }

            if (node->val != sub_node->val) {
                return false;
            }

            return dfs(node->left, sub_node->left) && dfs(node->right, sub_node->right);
        }

        void find_root(bool & result, TreeNode *node, TreeNode *sub_node) {
            if (node == nullptr) {
                return;
            }

            if (node->val == sub_node->val) {
                bool tmp = dfs(node, sub_node);
                if (tmp == true) {
                    result = true;
                    return;
                }
            }
            find_root(result, node->left, sub_node);
            find_root(result, node->right, sub_node);
        }
    public:
        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            bool result = false;
            find_root(result, root, subRoot);

            return result;
        }
};