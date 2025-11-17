#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *p = head;
    struct ListNode *n = NULL;
    while (p != NULL) {
        n = p->next;
        p->next = prev;
        prev = p;
        if (n == NULL) {
            break;
        }
        p = n;
    }
    return p;
}

int main(void) {
    return 0;
}