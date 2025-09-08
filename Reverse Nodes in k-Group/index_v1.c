/**
 * @file index_v1.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 * use a not standard solution
 */
#include "index.h"

struct ListNode* reverseKGroup(struct ListNode* head, int k) {

    if (k == 1) {
        return head;
    }

    int list_size = 0;
    struct ListNode *head_p = head;

    struct ListNode **node_list = malloc(sizeof(struct ListNode *) * 5000);

    while(head_p != NULL) {
        node_list[list_size++] = head_p;
        head_p = head_p->next;
    }
    
    struct ListNode *lag_p = NULL;
    for (int i = 0; i < list_size; i++) {
        if ((i + 1) % k == 0) {
            
            if (lag_p != NULL) {
                lag_p->next = node_list[i];
            }
            struct ListNode *list_next = node_list[i]->next;
            for (int j = 0, m = 1; j < k; j++, m++) {
                if (m % k == 0) {
                    lag_p = node_list[i - j];
                    node_list[i - j]->next = list_next;
                    break;
                }
                node_list[i - j]->next = node_list[i - m];
            }
        }
    }

    return node_list[k-1];
}


int main(void) {
    return 0;
}