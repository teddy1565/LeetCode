#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct ListNode {
    int val;
    struct ListNode *next;
} ListNode;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head);