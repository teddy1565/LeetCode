#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

struct ListNode* reverseKGroup(struct ListNode* head, int k);