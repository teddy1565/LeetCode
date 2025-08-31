#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode* removeNthFromEnd(struct ListNode* head, int n);