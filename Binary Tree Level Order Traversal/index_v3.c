#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

struct Answer {
    int col_size;
    int *val;
    struct Answer *next;
} Answer;

int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    (*returnSize) = 0;
    if (root == NULL) {
        return NULL;
    }
    struct TreeNode **bfs_queue = (struct TreeNode **) malloc(sizeof(struct TreeNode *) * 2000);
    struct TreeNode **tmp_queue = (struct TreeNode **) malloc(sizeof(struct TreeNode *) * 2000);

    int bfs_queue_size = 1;
    bfs_queue[0] = root;

    struct Answer *answer = (struct Answer *) malloc(sizeof(struct Answer));
    answer->next = NULL;
    struct Answer *answer_p = answer;

    while (bfs_queue_size > 0) {
        (*returnSize) += 1;
        answer_p->col_size = bfs_queue_size;
        answer_p->val = (int *) malloc(sizeof(int) * bfs_queue_size);
        int tmp_queue_size = 0;
        for (int i = 0; i < bfs_queue_size; i++) {
            answer_p->val[i] = bfs_queue[i]->val;
            if (bfs_queue[i]->left != NULL) {
                tmp_queue[tmp_queue_size++] = bfs_queue[i]->left;
            }
            if (bfs_queue[i]->right != NULL) {
                tmp_queue[tmp_queue_size++] = bfs_queue[i]->right;
            }
        }
        memcpy(bfs_queue, tmp_queue, sizeof(struct TreeNode *) * tmp_queue_size);
        bfs_queue_size = tmp_queue_size;
        if (bfs_queue_size > 0) {
            answer_p->next = (struct Answer *) malloc(sizeof(struct Answer));
            answer_p = answer_p->next;
            answer_p->next = NULL;
        }
    }
    
    printf("%d\n", (*returnSize));
    (*returnColumnSizes) = (int *) malloc(sizeof(int) * (*returnSize));
    int **res = (int **) malloc(sizeof(int *) * (*returnSize));
    int res_index = 0;
    answer_p = answer;
    while (answer_p != NULL) {
        // printf("[");
        // for (int i = 0; i < answer_p->col_size; i++) {
        //     printf("%d ", answer_p->val[i]);
        // }
        // printf("]\n");

        res[res_index] = &(*answer_p->val);
        (*returnColumnSizes)[res_index] = answer_p->col_size;
        res_index += 1;
        answer_p = answer_p->next;
    }

    return res;
}