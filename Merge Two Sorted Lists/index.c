/**
 * @file index.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-01
 * 
 * @copyright Copyright (c) 2025
 * 
 */

// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]
// Example 2:

// Input: list1 = [], list2 = []
// Output: []
// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]
#include "index.h"

struct ListNode* mock_data(int *vals, int valsSize) {
    struct ListNode *p_head = NULL;
    struct ListNode *p = NULL;
    for (int i = 0; i < valsSize; i++) {
        struct ListNode *node = (struct ListNode *) malloc(sizeof(struct ListNode));
        node->val = vals[i];
        node->next = NULL;
        if (p_head == NULL) {
            p_head = node;
            p = node;
        } else {
            p->next = node;
            p = node;
        }
    }
    return p_head;
}

void print_answer(const struct ListNode *list) {
    struct ListNode *l = (struct ListNode *)list;
    while(l != NULL) {
        printf("%d -> ", l->val);
        l = l->next;
    }
    printf("NULL\n");

}

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2) {
    

    if (list1 == NULL && list2 != NULL) {
        return list2;
    } else if (list1 != NULL && list2 == NULL) {
        return list1;
    } else if (list1 == NULL && list2 == NULL) {
        return NULL;
    }


    struct ListNode *list_head = NULL;
    struct ListNode *list_stage = NULL;

    

    if (list1->val > list2->val) {
        list_head = list2;
        list_stage = list1;
    } else {
        list_head = list1;
        list_stage = list2;
    }

    struct ListNode *list_p = list_head;

    // Input: list1 = [1,2,4], list2 = [1,3,4]
    // Output: [1,1,2,3,4,4]

    while(list_p != NULL) {
        struct ListNode *next_p = list_p->next;

        if (next_p == NULL) {
            list_p->next = list_stage;
            list_p = list_stage;
            list_stage = next_p;
        } else if (list_stage == NULL) {
            break;
        } else if (next_p->val > list_stage->val) {
            list_p->next = list_stage;
            list_p = list_stage;
            list_stage = next_p;
        } else {
            list_p = next_p;
        }
    }

    return list_head;
}

int main(void) {
    int n1[2] = {1, 2};
    int n2[3] = {1, 3, 4};
    struct ListNode *test_case_01_1 = mock_data(n1, 2);
    struct ListNode *test_case_01_2 = mock_data(n2, 3);

    struct ListNode *ans = mergeTwoLists(test_case_01_1, test_case_01_2);
    print_answer(ans);
    
    return 0;
}