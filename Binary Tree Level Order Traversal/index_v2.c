#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

struct TreeListNode {
    int level;
    int col_size;
    int *val;
    struct TreeListNode *next;
} TreeListNode;


struct TreeListNode* level_order(struct TreeNode* left, struct TreeNode* right, int level) {

    if (left == NULL && right == NULL) {
        return NULL;
    }
    
    struct TreeListNode *tree_list_node = (struct TreeListNode *) malloc(sizeof(TreeListNode));
    tree_list_node->level = level;
    tree_list_node->next = NULL;

    if (left != NULL && right != NULL) {
        tree_list_node->col_size = 2;
        tree_list_node->val = (int *) malloc(sizeof(int) * 2);
        tree_list_node->val[0] = left->val;
        tree_list_node->val[1] = right->val;
        struct TreeListNode *left_node = level_order(left->left, left->right, level + 1);
        struct TreeListNode *right_node = level_order(right->left, right->right, level + 1);
        if (left_node != NULL && right_node != NULL) {
            tree_list_node->next = left_node;
            struct TreeListNode *p = left_node;
            while (p->next != NULL) {
                p = p->next;
            }
            p->next = right_node;
        } else if (left_node != NULL) {
            tree_list_node->next = left_node;
        } else if (right_node != NULL) {
            tree_list_node->next = right_node;
        }
    } else if (left != NULL) {

        tree_list_node->col_size = 1;
        tree_list_node->val = (int *) malloc(sizeof(int) * 1);
        tree_list_node->val[0] = left->val;
        tree_list_node->next = level_order(left->left, left->right, level + 1);
        
    } else if (right != NULL) {
        tree_list_node->col_size = 1;
        tree_list_node->val = (int *) malloc(sizeof(int) * 1);
        tree_list_node->val[0] = right->val;
        tree_list_node->next = level_order(right->left, right->right, level + 1);
    }
    

    return tree_list_node;
}

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    (*returnSize) = 0;
    if (root == NULL) {
        return NULL;
    }
    int level_list[3000] = { 0 };
    int answer_index[3000] = { 0 };

    struct TreeListNode *s = (struct TreeListNode *) malloc(sizeof(struct TreeListNode));
    s->level = 0;
    s->col_size = 1;
    s->val = (int *) malloc(sizeof(int) * 1);
    s->val[0] = root->val;
    s->next = level_order(root->left, root->right, s->level + 1);
    struct TreeListNode *sp = s;
    while (sp != NULL) {
        if (sp->level > (*returnSize)) {
            (*returnSize) = sp->level;
        }
        level_list[sp->level] += sp->col_size;
        sp = sp->next;
    }
    (*returnSize) += 1;

    int **answer = (int **) malloc(sizeof(int *) * (*returnSize));
    (*returnColumnSizes) = (int *) malloc(sizeof(int) * (*returnSize));
    for (int current_level = 0; current_level < (*returnSize); current_level++) {
        answer[current_level] = (int *) malloc(sizeof(int) * level_list[current_level]);
        (*returnColumnSizes)[current_level] = level_list[current_level];
        sp = s;
        while(sp != NULL) {
            if (sp->level == current_level) {
                for (int j = 0; j < sp->col_size; j++) {
                    answer[current_level][answer_index[current_level]++] = sp->val[j];
                }
            }
            sp = sp->next;
        }
    }
    sp = s;
    while (sp != NULL) {
        struct TreeListNode *np = sp->next;
        free(sp->val);
        free(sp);
        sp = np;
    }
    return answer;
}