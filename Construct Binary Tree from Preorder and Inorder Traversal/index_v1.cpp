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
 * 
 * preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
 * 
 * [3,9,20,15,7]
 * [9,3,15,20,7]
 * 
 * [3,9,20,null,null,15,7]
 * 
 * preorder = [4,2,1,3,6,5,7], inorder = [1,2,3,4,5,6,7]
 * 
 * if root is 4, left child is 2
 * (preorder index +1 for 4, and inorder index small then 4)
 * 
 * 2 parent -> 4
 * if 1 index small then 4, means 1 is 2 child  
 *      if 1 index small then 2 means left node, else right node
 * if 1 index bigger then 4, means 1 not 2 child
 *      1 is right node or others....
 * 
 * 
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(): val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x): val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right): val(x), left(left), right(right) {}
};

class Solution {

    private:
        TreeNode* build_tree_helper(const int preorder_size, const int inorder_size, std::unordered_map<int, int> & inorder_map, std::vector<int> & preorder, int index, int *deepth_index) {
            if (index >= preorder_size) {
                return nullptr;
            }

            TreeNode *root = new TreeNode(preorder[index]);
            int inorder_index_for_root = inorder_map[preorder[index]];

            if ((index + 1) < preorder_size) {
                int left = preorder[index + 1];
                int inorder_index_for_left = inorder_map[left];

                if ((index + 1) > (*deepth_index)) {
                    (*deepth_index) = index + 1;
                }

                if (inorder_index_for_left < inorder_index_for_root) {
                    root->left = build_tree_helper(preorder_size, inorder_size, inorder_map, preorder, index + 1, deepth_index);
                } else {
                    root->right = build_tree_helper(preorder_size, inorder_size, inorder_map, preorder, index + 1, deepth_index);
                }
            }

            if (root->right == nullptr && ((*deepth_index) + 1) < preorder_size) {
                std::cout << (*deepth_index) << ", " << (*deepth_index) + 1 << std::endl;
                index = (*deepth_index) + 1;
                root->right = build_tree_helper(preorder_size, inorder_size, inorder_map, preorder, index, deepth_index);
            }

            return root;

        }

    public:
        TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {

            std::unordered_map<int, int> inorder_map;
            int preorder_size = preorder.size();
            int inorder_size = inorder.size();

            int deepth_index = 0;
            
            for (int i = 0; i < inorder_size; i++) {
                inorder_map[inorder[i]] = i;
            }
            
            TreeNode *root = this->build_tree_helper(preorder_size, inorder_size, inorder_map, preorder, 0, &deepth_index);
            return root;
        }
};