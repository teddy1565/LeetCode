#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) {
        this->val = x;
        this->next = nullptr;
    }
};
class Solution {
    public:
        bool hasCycle(ListNode *head) {
            if (head == nullptr || head->next == nullptr) {
                return false;
            }
            
            ListNode *slow = head;
            ListNode *fast = head;
            while (fast && fast->next) {
                slow = slow->next;
                fast = fast->next->next;

                if (slow == fast) {
                    return true;
                }
            }

            return false;
        }
};