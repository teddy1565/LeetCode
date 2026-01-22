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

        void dfs(std::vector<int>& result, TreeNode *node) {
            if (node == nullptr) {
                result.push_back(INT_MIN);
                return;
            }
            
            result.push_back(node->val);
            dfs(result, node->left);
            dfs(result, node->right);
        }
    public:
        bool isSubtree(TreeNode* root, TreeNode* subRoot) {
            std::vector<int> root_tree_array;
            std::vector<int> sub_root_tree_array;
            dfs(root_tree_array, root);
            dfs(sub_root_tree_array, subRoot);

            int root_tree_array_size = root_tree_array.size();
            int sub_root_tree_array_size = sub_root_tree_array.size();

            bool result = false;
            
            for (int i = 0; i < root_tree_array_size; i++) {
                if (root_tree_array[i] == sub_root_tree_array[0] && (i + (sub_root_tree_array_size - 1)) < root_tree_array_size) {
                    bool find = true;
                    for (int j = 0, k = sub_root_tree_array_size - 1; j < k; j++, k--) {
                        if (root_tree_array[i + j] != sub_root_tree_array[j] || root_tree_array[i + k] != sub_root_tree_array[k]) {
                            find = false;
                            break;
                        }
                    }
                    if (find == true) {
                        result = true;
                        break;
                    }
                }
            }

            return result;
        }
};