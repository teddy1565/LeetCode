#include "index.h"

struct ListNode* swapPairs(struct ListNode* head) {

    if (head == NULL) {
        return NULL;
    } else if (head->next == NULL) {
        return head;
    }

    struct ListNode *head_p = head;

    struct ListNode **p = (struct ListNode **) malloc(sizeof(struct ListNode *) * 100);

    int p_index = 0;
    while(head_p != NULL) {
        p[p_index++] = head_p;
        head_p = head_p->next;
    }

    struct ListNode *lag_p = NULL;
    for (int i = 0; i < p_index; i+=2) {
        if ((i + 1) >= p_index) {
            p[i]->next = NULL;
            break;
        }
        p[i]->next = p[i + 1]->next;
        p[i + 1]->next = p[i];
        if (lag_p != NULL) {
            lag_p->next = p[i + 1];
        }
        lag_p = p[i];
    }

    return p[1];
}

int main(void) {
    return 0;
}