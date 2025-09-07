/**
 * @file index_v5.c
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
    
    struct ListNode *current_p = head;
    while(current_p != NULL) {
        struct ListNode *tail = current_p;
        for (int i = 0; i < k; i++) {
            tail = tail->next;
            if (tail == NULL) {
                return head;
            }
        }
    }

    return head;
    
}


int main(void) {
    return 0;
}