/**
 * @file index_v3.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "index.h"

struct ListNode *reverseion(struct ListNode* head) {

}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {

    if (k == 1) {
        return head;
    }

    int total = 0;

    struct ListNode *p = head;
    struct ListNode *tail = NULL;
    while (p != NULL) {
        
    }

    p = head;

    struct ListNode *ans = NULL;
    
    for (int i = 0; i < (total - (total % k)); i++) {
        if ((i + 1) % k == 0) {
            struct ListNode *np = p->next;
            p->next = NULL;
            if (ans == NULL) {
                ans = reverseion(tail, np);
            } else {
                struct ListNode *real_tail = reverseion(tail, np);
            }
            p = np;
        } else if ((i + 1) % k == 1) {
            if (tail != NULL) {
                tail->next = p;
            }
            tail = p;
            p = p->next;
        }
    }

    printf("%d\n", head->val);

    return p;
}


int main(void) {
    return 0;
}