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
        
        TreeNode *build_tree_helper(std::unordered_map<int, int> & inorder_map,

                                    std::vector<int> & preorder,
                                    int p_left, int p_right,

                                    std::vector<int> & inorder,
                                    int i_left, int i_right
        ) {
            if (p_left > p_right || i_left > i_right) {
                return nullptr;
            }

            // get p_left node in inorder index
            int i = inorder_map[preorder[p_left]];

            if (i < i_left || i > i_right) {
                i = 0;
            }

            // choose p_left in preorder
            TreeNode *current = new TreeNode(preorder[p_left]);

            current->left = build_tree_helper(
                inorder_map, 
                preorder,
                //  p_left + 1 到 p_left + len
                p_left + 1,          // preorder left barrier
                p_left + i - i_left, // preorder right barrier
                inorder,
                i_left,              // support select next range
                i - 1
            );
            current->right = build_tree_helper(
                inorder_map,
                preorder,
                // p_left + i - i_left + 1 ==> p_right
                p_left + i - i_left + 1,    // right node, preorder left barrier
                p_right,                    // right node, preorder right barrier
                inorder,
                i + 1,
                i_right
            );


            
            return current;
        }

    public:
        TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
            std::unordered_map<int, int> inorder_map;
            for (int i = 0; i < inorder.size(); i++) {
                inorder_map[inorder[i]] = i;
            }
            return build_tree_helper(
                inorder_map,
                preorder,
                0,
                preorder.size() - 1,
                inorder,
                0,
                inorder.size() - 1
            );
        }
};