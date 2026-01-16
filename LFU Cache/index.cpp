#include <iostream>
#include <vector>
#include <unordered_map>
#include <list>

class LFUCache {

    private:
        
        int current_size;
        int max_size;

        struct LFU_Node {
            int key;
            int value;
            int count;
            LFU_Node *prev;
            LFU_Node *next;
            
            LFU_Node(int key, int value) {
                this->key = key;
                this->value = value;
                this->count = 0;
                this->prev = nullptr;
                this->next = nullptr;
            };
        };

        LFU_Node *dummy_head;
        LFU_Node *dummy_tail;

        std::unordered_map<int, LFU_Node *> node_map;

        void remove_node(LFU_Node *node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        void add_node(LFU_Node *node) {
            LFU_Node *n = this->dummy_head;
            while (n != NULL) {
                if (n->count > node->count) {
                    n = n->next;
                } else if (n->count <= node->count) {
                    node->next = n;
                    node->prev = n->prev;
                    
                    n->prev->next = node;
                    n->prev = node;
                    break;
                }
            }
        }

    public:
        LFUCache(int capacity) {
            this->dummy_head = new LFU_Node(0, 0);
            this->dummy_tail = new LFU_Node(0, 0);
            this->current_size = 0;
            this->max_size = capacity;

            this->dummy_head->next = this->dummy_tail;
            this->dummy_tail->prev = this->dummy_head;

            this->dummy_head->count = INT_MAX;
            this->dummy_tail->count = INT_MIN;
        }
        
        int get(int key) {
            if (this->node_map.find(key) == this->node_map.end()) {
                return -1;
            }
            
            LFU_Node *node = this->node_map[key];
            this->remove_node(node);
            node->count += 1;
            this->add_node(node);
            return node->value;
        }
        
        void put(int key, int value) {
            if (this->node_map.find(key) != this->node_map.end()) {
                LFU_Node *node = this->node_map[key];
                this->remove_node(node);
                node->value = value;
                node->count += 1;
                this->add_node(node);
            } else {
                LFU_Node *node = new LFU_Node(key, value);
                this->current_size += 1;
                if (this->current_size > this->max_size) {
                    
                    LFU_Node *n = this->dummy_tail->prev;
                    this->remove_node(n);
                    this->current_size -= 1;
                    this->node_map.erase(n->key);
                    delete n;
                }
                this->node_map.insert({key, node});
                this->add_node(node);
            }
        }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */