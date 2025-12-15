#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

struct TreeListNode {
    int col_size;
    int *v;
    struct TreeListNode *next;
} TreeListNode;


struct TreeListNode* level_order(struct TreeNode *left, struct TreeNode *right) {
    
    if (left == NULL && right == NULL) {
        return NULL;
    }

    struct TreeListNode *s = (struct TreeListNode *) malloc(sizeof(struct TreeListNode));
    s->next = NULL;
    if (left != NULL && right != NULL) {
        s->col_size = 2;
        s->v = (int *) malloc(sizeof(int) * s->col_size);
        s->v[0] = left->val;
        s->v[1] = right->val;
        struct TreeListNode *s_left = level_order(left->left, left->right);
        struct TreeListNode *s_right = level_order(right->left, right->right);
        if (s_left != NULL && s_right != NULL) {
            s->next = s_left;
            s_left->next = s_right;
        } else if (s_right != NULL) {
            s->next = s_right;
        } else if (s_left != NULL) {
            s->next = s_left;
        }
    } else if (left != NULL) {
        s->col_size = 1;
        s->v = (int *) malloc(sizeof(int) * s->col_size);
        s->v[0] = left->val;
        s->next = level_order(left->left, left->right);
    } else if (right != NULL) {
        s->col_size = 1;
        s->v = (int *) malloc(sizeof(int) * s->col_size);
        s->v[0] = right->val;
        s->next = level_order(right->left, right->right);
    }

    return s;
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
    struct TreeNode *p = root;
    struct TreeListNode *s = (struct TreeListNode *) malloc(sizeof(struct TreeListNode));
    s->col_size = 1;
    s->v = (int *) malloc(sizeof(int) * 1);
    s->v[0] = p->val;
    s->next = level_order(p->left, p->right);
    
    struct TreeListNode *sp = s;
    while (sp != NULL) {
        printf("[");
        for (int i = 0; i < sp->col_size; i++) {
            printf("%d ", sp->v[i]);
        }
        printf("]\n");
        (*returnSize) += 1;
        sp = sp->next;
    }
    int **answer = (int **) malloc(sizeof(int *) * (*returnSize));
    (*returnColumnSizes) = (int *) malloc(sizeof(int) * (*returnSize));
    sp = s;
    int count = 0;
    for (int i = 0; i < (*returnSize); i++) {
        answer[i] = &(*sp->v);
        (*returnColumnSizes)[i] = sp->col_size;
        sp = sp->next;
    }
    return answer;
}