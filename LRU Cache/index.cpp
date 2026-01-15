#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>

class LRUCache {
    private:
        struct LRU_Node {
            int key;
            int value;
            LRU_Node *prev;
            LRU_Node *next;

            LRU_Node(int k, int v) {
                this->key = k;
                this->value = v;
                this->prev = nullptr;
                this->next = nullptr;
            };
        };

        int current_size;
        int max_size;

        LRU_Node *dummy_head;
        LRU_Node *dummy_tail;

        std::unordered_map<int, LRU_Node *> node_map;

        void remove_node(LRU_Node *node) {
            node->prev->next = node->next;
            node->next->prev = node->prev;
        }

        void add_to_head(LRU_Node *node) {
            node->next = dummy_head->next;
            node->prev = dummy_head;

            dummy_head->next->prev = node;
            dummy_head->next = node;
        }
    public:
        LRUCache(int capacity) {
            this->current_size = 0;
            this->max_size = capacity;
            this->dummy_head = new LRU_Node(0, 0);
            this->dummy_tail = new LRU_Node(0, 0);

            this->dummy_head->next = this->dummy_tail;
            this->dummy_tail->prev = this->dummy_head;
        }
        
        int get(int key) {
            if (this->node_map.find(key) == this->node_map.end()) {
                return -1;
            }
            LRU_Node *n = this->node_map[key];
            this->remove_node(n);
            this->add_to_head(n);
            return n->value;
        }
        
        void put(int key, int value) {
            if (this->node_map.find(key) != this->node_map.end()) {
                LRU_Node *n = this->node_map[key];
                this->remove_node(n);
                n->value = value;
                this->add_to_head(n);
            } else {
                LRU_Node *n = new LRU_Node(key, value);
                this->node_map.insert({key, n});
                this->add_to_head(n);
                this->current_size += 1;

                if (this->current_size > this->max_size) {
                    LRU_Node *tail_n = this->dummy_tail->prev;
                    this->node_map.erase(tail_n->key);
                    this->remove_node(tail_n);
                    this->current_size -= 1;
                    delete tail_n;
                }
            }
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */