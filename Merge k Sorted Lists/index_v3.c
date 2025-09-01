/**
 * @file index_v3.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-01
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

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {

    
    struct ListNode *list_head = NULL;
    for (int i = 0; i < listsSize; i++) {
        if (lists[i] == NULL) {
            continue;
        }
        list_head = lists[i];
        lists[i] = lists[i]->next;
        break;
    }
    if (list_head == NULL) {
        return NULL;
    }

    struct ListNode *list_p = list_head;
    
    while(list_p != NULL) {
        for (int i = 0; i < listsSize; i++) {
            if (lists[i] == NULL) {
                continue;
            } else if (lists[i]->val > list_p->val) {
                if (list_p->next == NULL) {
                    list_p->next = lists[i];
                    lists[i] = lists[i]->next;
                } else if (list_p->next->val > lists[i]->val) {
                    struct ListNode *temp_p1 = lists[i];
                    struct ListNode *temp_p2 = list_p->next;

                    lists[i] = lists[i]->next;
                    list_p->next = temp_p1;
                    temp_p1->next = temp_p2;
                    list_p = list_p->next;
                    


                    // struct ListNode *temp_p = list_p->next;
                    // list_p->next = lists[i];
                    // lists[i] = lists[i]->next;
                    // list_p = list_p->next;
                    // list_p->next = temp_p;
                } else {
                    list_p = list_p->next;
                }
            } else {
                struct ListNode *temp_p1 = lists[i];
                struct ListNode *temp_p2 = list_p;
                lists[i] = lists[i]->next;
                temp_p1->next = temp_p2;
                list_p = temp_p1;
            }
        }
    }

    return list_head;
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
    datasets_01[0][0] = 1;
    datasets_01[0][1] = 4;
    datasets_01[0][2] = 5;

    datasets_01[1][0] = 1;
    datasets_01[1][1] = 3;
    datasets_01[1][2] = 4;

    datasets_01[2][0] = 2;
    datasets_01[2][1] = 6;

    struct ListNode **test_data = mock_data(datasets_01, rows, cols);
    print_dataset((const struct ListNode **)test_data, rows);

    printf("---------------\n");
    
    struct ListNode *answer = mergeKLists(test_data, rows);
    print_answer(answer);
    return 0;
}