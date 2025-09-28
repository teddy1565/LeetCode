#include "index.h"

struct ListNode* deleteDuplicates(struct ListNode* head) {
    if (head == NULL) {
        return NULL;
    } else if (head->next == NULL) {
        return head;
    }
    struct ListNode *p = head;
    struct ListNode *prev = head;
    while (head != NULL && head->next != NULL) {

        if (head->val != head->next->val) {
            prev->next = head->next;
            prev = prev->next;
        }

        head = head->next;
    }

    prev->next = NULL;
    return p;
}

int main(void) {
    return 0;
}