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
 * 
 *          4
 *      2       6
 *    1   3   5   7
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
 * 
 * preorder = [1,2,4,5,3,6], inorder = [4,2,5,1,3,6]
 * 
 * 
 *          1
 *       2     3
 *     4   5     6
 * 
 * 
 * (*index) = 2, inorder_index_for_left = 2, parent_index_for_parent_root = 1, inorder_index_for_root = 0, preorder_n = 5
 * 
 * (*index) = 3, inorder_index_for_left = 4, parent_index_for_parent_root = 1, inorder_index_for_root = 2, preorder_n = 3
 * (*index) = 4, inorder_index_for_left = 5, parent_index_for_parent_root = 3, inorder_index_for_root = 4, preorder_n = 6
 * 
 * 
 * 
 * preorder = [1,2,3], inorder = [1,2,3]
 * 
 *          1
 *             2
 *               3
 * 
 *          (*index) = 1, 
 *          inorder_index_for_left = 2, 
 *          parent_index_for_parent_root = 0, 
 *          inorder_index_for_root = 1, 
 *          preorder_n = 3
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
        /**
         *  0 | 3 | 1
            1 | 1 | 0
            2 | 0 | 2
            3 | 2 | 5
            4 | 5 | 4
            5 | 4 | 6
         */
        TreeNode* build_tree_helper(const int preorder_size, const int inorder_size, std::unordered_map<int, int> & inorder_map, std::vector<int> & preorder, int *index, int parent_index) {
            if ((*index) >= preorder_size) {
                return nullptr;
            }

            // init root node
            TreeNode *root = new TreeNode(preorder[(*index)]);

            // get parent node for root node index
            int root_parent_index_in_inorder = parent_index;

            // root node index in inordermap
            int inorder_index_for_root = inorder_map[preorder[(*index)]];

            // if (*index) no next, just return
            if (((*index) + 1) >= preorder_size) {
                return root;
            }

            

            // get child node index from preorder
            int child_node_index = preorder[(*index) + 1];

            // child node inorder index
            int inorder_index_for_child_node = inorder_map[child_node_index];


            if (root_parent_index_in_inorder >= 0) {

                /**
                 * @brief 
                 * if inorder_index_for_next_node bigger then root's parent index
                 * 
                 * it's means the next node is a same level for root_node in parent right node
                 * 
                 */
                if (inorder_index_for_child_node > root_parent_index_in_inorder) {

                    /**
                     * @brief 
                     * 
                     * if current_next_child_node index < root inorder index
                     * 
                     * mean inorder_index_for_root > root_parent_index_in_inorder
                     * 
                     */
                    if (inorder_index_for_child_node < inorder_index_for_root) {
                        (*index) += 1;
                        root->left = build_tree_helper(preorder_size, inorder_size, inorder_map, preorder, index, inorder_index_for_root);

                        (*index) += 1;
                        root->right = build_tree_helper(preorder_size, inorder_size, inorder_map, preorder, index, inorder_index_for_root);
                    } else if (inorder_index_for_child_node > inorder_index_for_root) {
                        
                        // (*index) += 1;
                        // root->right = build_tree_helper(preorder_size, inorder_size, inorder_map, preorder, index, root_parent_index_in_inorder);
                    }
                    return root;
                } else {
                    if (inorder_index_for_child_node < inorder_index_for_root) {
                        (*index) += 1;
                        root->left = build_tree_helper(preorder_size, inorder_size, inorder_map, preorder, index, inorder_index_for_root);

                        (*index) += 1;
                        root->right = build_tree_helper(preorder_size, inorder_size, inorder_map, preorder, index, inorder_index_for_root);
                    } else {
                        // (*index) += 1;
                        // root->right = build_tree_helper(preorder_size, inorder_size, inorder_map, preorder, index, root_parent_index_in_inorder);
                    }

                    return root;
                }
            }

            if (inorder_index_for_child_node < inorder_index_for_root) {
                (*index) += 1;
                root->left = build_tree_helper(preorder_size, inorder_size, inorder_map, preorder, index, inorder_index_for_root);

                (*index) += 1;
                root->right = build_tree_helper(preorder_size, inorder_size, inorder_map, preorder, index, inorder_index_for_root);
            } else {
                (*index) += 1;
                root->right = build_tree_helper(preorder_size, inorder_size, inorder_map, preorder, index, root_parent_index_in_inorder);
            }

            return root;

        }

    public:
        TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {

            std::unordered_map<int, int> inorder_map;
            int preorder_size = preorder.size();
            int inorder_size = inorder.size();

            int index = 0;
            
            for (int i = 0; i < inorder_size; i++) {
                inorder_map[inorder[i]] = i;
            }
            
            TreeNode *root = this->build_tree_helper(preorder_size, inorder_size, inorder_map, preorder, &index, -1);
            return root;
        }
};