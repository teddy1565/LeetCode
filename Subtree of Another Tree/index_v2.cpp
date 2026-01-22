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

        void find_root(std::queue<TreeNode *>& node_queue, TreeNode *node, int val) {
            if (node == nullptr) {
                return;
            }

            if (node->val == val) {
                node_queue.push(node);
            }
            find_root(node_queue, node->left, val);
            find_root(node_queue, node->right, val);
        }
    public:
        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            std::queue<TreeNode *> node_queue;
            bool result = false;
            find_root(node_queue, root, subRoot->val);

            while (node_queue.size() > 0) {
                TreeNode *n = node_queue.front();
                node_queue.pop();
                result = dfs(n, subRoot);
                if (result == true) {
                    break;
                }
            }
            return result;
        }
};