#include "index.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode *p = head;
    int total = 0;

    while (p != NULL) {
        total++;
        p = p->next;
    }

    total = total - n;
    
    if (total == 0) {
        head = head->next;
        return head;
    }

    p = head;
    
    while ((--total) > 0) {
        p = p->next;
    }

    if (p->next != NULL && p->next->next != NULL) {
        p->next = p->next->next;
    } else if (p->next != NULL && p->next->next == NULL) {
        p->next = NULL;
    } else if (p->next == NULL) {
        head = NULL;
    }

    return head;
}