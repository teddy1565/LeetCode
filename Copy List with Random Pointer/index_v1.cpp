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

class Node {
    public:
        int val;
        Node* next;
        Node* random;
        
        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
};

/**
 * @brief 
 * 
 * we can observe the pattern
 * 
 * next always pointer to next, no loopback
 * 
 * 
 */
class Solution {
    public:
        Node* copyRandomList(Node* head) {
            if (head == nullptr) {
                return nullptr;
            }
            
            Node* p = head;
            Node* answer_head = new Node(head->val);
            Node* t = answer_head;

            std::unordered_map<Node *, Node *> hash_map;

            hash_map[p] = t;

            while (p != nullptr) {
                if (p->next != nullptr) {
                    if (hash_map.find(p->next) != hash_map.end()) {
                        t->next = hash_map[p->next];
                    } else {
                        t->next = new Node(p->next->val);
                        hash_map[p->next] = t->next;
                    }
                }

                if (p->random == p) {
                    t->random = t;
                } else if (p->random != nullptr) {
                    
                    if (hash_map.find(p->random) != hash_map.end()) {
                        t->random = hash_map[p->random];
                    } else {
                        t->random = new Node(p->random->val);
                        hash_map[p->random] = t->random;
                    }
                } else {
                    t->random = nullptr;
                }

                p = p->next;
                t = t->next;
            }
            

            return answer_head;
        }
};