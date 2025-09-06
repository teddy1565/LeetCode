/**
 * @file index_v2.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-06
 * 
 * @copyright Copyright (c) 2025
 * 
 * i want try recursion, but i feel not good.
 */
#include "index.h"


struct ListNode *reverse_func(struct ListNode* head, struct ListNode *next_p, int n, int k, int total) {

    if (next_p == NULL || head == NULL) {
        return head;
    } else if (n > total) {
        return next_p;
    }

    struct ListNode *res = NULL;

    if (n % k == 0) {

        struct ListNode *nn = next_p->next;
        if (nn != NULL) {
            head->next = reverse_func(nn, nn->next, n + 1, k, total);
        } else {
            head->next = NULL;
        }
        next_p->next = head;    // 2
        
        return next_p;
    }

    head->next = next_p->next;
    next_p->next = head;
    res = reverse_func(next_p, head->next, n + 1, k, total);
    // res->next = next_p;
    return res;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {

    if (k == 1) {
        return head;
    }

    int c = 1;
    int total = 0;

    struct ListNode *p = head;
    struct ListNode *cp = head;
    struct ListNode *lag_p = NULL;
    while (cp != NULL) {
        cp = cp->next;
        total++;
    }

    

    return reverse_func(p, p->next, c + 1, k, total);
}


int main(void) {
    return 0;
}