/**
 * @file index_v7.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-08
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "index.h"


struct ListNode* reverseKGroup(struct ListNode* head, int k) {

    if (k == 1) {
        return head;
    }
    
    struct ListNode *p = head;
   
    struct ListNode *real_head = NULL;
    struct ListNode *prev_group_end = NULL;

    while(p != NULL) {
        struct ListNode *tail = p;
        for (int i = 1; i < k; i++) {
            tail = tail->next;
            if (tail == NULL) {
                break;
            }
        }
        
        if (tail == NULL) {
            break;
        }

        struct ListNode *head_p = p;
        struct ListNode *prev_p = NULL;
        for (int i = 1; i < k; i++) {
            struct ListNode *tmp = head_p;
            head_p = p->next;
            p->next = head_p->next;
            head_p->next = tmp;
            if (prev_p != NULL) {
                tmp->next = prev_p;
            }
            prev_p = tmp;
        }
        
        if (real_head == NULL) {
            real_head = head_p;
        }


        if (prev_group_end != NULL) {
            prev_group_end->next = tail;
        }
        prev_group_end = p;
        p = p->next;
    }

    if (real_head == NULL) {
        return head;
    }

    return real_head;
    
}


int main(void) {
    return 0;
}