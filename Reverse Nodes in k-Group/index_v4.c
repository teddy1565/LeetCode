/**
 * @file index_v4.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-07
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "index.h"


struct ListNode* reverseKGroup(struct ListNode* head, int k) {

    if (k == 1) {
        return head;
    }

    int total = 0;

    struct ListNode *p = head;
    struct ListNode *lag_p = NULL;
    
    while (1) {
        struct ListNode *tail = p;
        for (int i = 0; i < k && tail != NULL; i++) {
            tail = tail->next;
        }
        if (tail == NULL) {
            break;
        }

        struct ListNode *current_p = p->next;
        struct ListNode *prev_p = NULL;
        while (current_p != tail) {
            p->next = current_p->next;
            current_p->next = p;
            prev_p = current_p;
        }

        
        struct ListNode *head_p = p->next;

        struct ListNode *current_p = NULL;
        struct ListNode *prev_p = NULL;
        for (int i = 0; i < k; i++) {
            current_p = p->next;
            p->next = current_p->next;
            if (prev_p == NULL) {
                current_p->next = p;
            } else {
                current_p->next = prev_p;
            }
            prev_p = current_p;
        }
        // struct ListNode *tail_next = tail->next;
        // tail->next = head_p;
        head_p->next = tail->next;
        tail->next = head_p;
        head_p = tail;

        if (lag_p != NULL) {
            lag_p->next = head_p;
        } else {
            head = head_p;
        }
        lag_p = p;

        p = p->next;
    }
    return head;
}


int main(void) {
    return 0;
}