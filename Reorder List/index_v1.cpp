#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <array>
#include <set>
#include <numeric>
#include <unordered_set>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
    private:
        
    public:
        /**
         * @brief 
         * 
         * L0 -> L1 -> L2 -> L3 -> ....... -> Ln-1 -> Ln
         * 
         * L0 -> Ln -> L1 -> Ln-1 -> L2 -> Ln-2
         * 
         * 
         * a b c d => d c b a
         * 
         * a -> b -> c -> d
         * a -> d -> b -> c
         * 
         * a b c d e => e d c b a
         * 
         * a -> b -> c -> d -> e    a
         * a -> e -> b -> c -> d    b
         * a -> e -> b -> d -> c    
         * @param head 
         */
        void reorderList(ListNode* head) {
            if (head == nullptr || head->next == nullptr || head->next->next == nullptr) {
                return;
            }

            std::stack<ListNode*> stack;
            ListNode *p = head;
            while (p != nullptr) {
                stack.push(p);
                p = p->next;
            }

            p = head;

            while (!stack.empty()) {
                ListNode *t = stack.top();
                stack.pop();
                t->next = p->next;
                p->next = t;
                p = t->next;
                if (p == t) {
                    break;
                }
            }

            p->next = nullptr;

        }
};