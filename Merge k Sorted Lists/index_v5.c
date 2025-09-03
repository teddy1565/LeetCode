/**
 * @file index_v5.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-03
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "index.h"

struct ListNode **mock_data(int **nums, int nums_row_size, int *nums_col_size) {
    if (nums_row_size < 1) {
        return NULL;
    }
    struct ListNode **p = (struct ListNode **) malloc(sizeof(struct ListNode *) * nums_row_size);
    for (int i = 0; i < nums_row_size; i++) {
        p[i] = NULL;
    }

    for (int i = 0; i < nums_row_size; i++) {
        if (nums_col_size[i] < 1) {
            continue;
        }
        struct ListNode *list_p = NULL;
        
        for (int j = 0; j < nums_col_size[i]; j++) {
            if (p[i] == NULL) {
                list_p = (struct ListNode *) malloc(sizeof(struct ListNode));
                list_p->next = NULL;
                list_p->val = nums[i][j];
                p[i] = list_p;
            } else {
                struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode)); 
                node->next = NULL;
                node->val = nums[i][j];
                list_p->next = node;
                list_p = node; 
            }
        }
    }

    return p;
}

void print_answer(const struct ListNode* list) {
    struct ListNode *l = (struct ListNode *) list;
    while (l != NULL) {
        printf("%d -> ", l->val);
        l = l->next;
    }
    printf("NULL\n");
}

void print_dataset(const struct ListNode **lists, int listsSize) {
    for (int i = 0; i < listsSize; i++) {
        struct ListNode *p = (struct ListNode *)lists[i];
        while(p != NULL) {
            printf("%d -> ", p->val);
            p = p->next;
        }
        printf("NULL\n");
    }
}


struct ListNode* mergeList(struct ListNode *l1, struct ListNode *l2) {
    if (l1 == NULL) {
        return l2;
    } else if (l2 == NULL) {
        return l1;
    }
    struct ListNode *head = NULL;
    struct ListNode *p = NULL;
    if (l1->val > l2->val) {
        p = l2;
        l2 = l2->next;
    } else {
        p = l1;
        l1 = l1->next;
    }
    head = p;
    while (l1 != NULL || l2 != NULL) {
        if (l2 == NULL) {
            p->next = l1;
            l1 = l1->next;
            p = p->next;
        } else if (l1 == NULL) {
            p->next = l2;
            l2 = l2->next;
            p = p->next;
        } else if (l1->val > l2->val) {
            struct ListNode *l2_tmp = l2;
            l2 = l2->next;
            p->next = l2_tmp;
            p = p->next;
        } else {
            struct ListNode *l1_tmp = l1;
            l1 = l1->next;
            p->next = l1_tmp;
            p = p->next;
        }
    }
    return head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

    if (listsSize == 0) {
        return NULL;
    }

    struct ListNode *p = NULL;

    for (int i = 0; i < listsSize; i++) {
        if (lists[i] == NULL) {
            continue;
        }
        p = mergeList(p, lists[i]);
    }

    return p;

}


int main(void) {
    int rows = 3;
    int *cols = (int *) malloc(sizeof(int) * rows);
    cols[0] = 3;
    cols[1] = 3;
    cols[2] = 2;

    int **datasets_01 = (int **) malloc(sizeof(int *) * rows);
    for (int i = 0; i < rows; i++) {
        datasets_01[i] = (int *) malloc(sizeof(int) * cols[i]);
    }
    datasets_01[0][0] = 3;
    datasets_01[0][1] = 4;
    datasets_01[0][2] = 5;

    datasets_01[1][0] = 1;
    datasets_01[1][1] = 3;
    datasets_01[1][2] = 4;

    datasets_01[2][0] = 2;
    datasets_01[2][1] = 6;

    //[[3,4,5],[1,3,4],[2,6]]

    struct ListNode **test_data = mock_data(datasets_01, rows, cols);
    print_dataset((const struct ListNode **)test_data, rows);

    printf("---------------\n");
    
    struct ListNode *answer = mergeKLists(test_data, rows);
    print_answer(answer);
    return 0;
}