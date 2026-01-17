#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <string>
#include <map>

class TimeMap {

    private:
        
        struct TimeMapNode {
            std::string key;
            std::string value;
            int timestamp;

            TimeMapNode(std::string key, std::string value, int timestamp) {
                this->key = key;
                this->value = value;
                this->timestamp = timestamp;
            }
        };

        std::unordered_map<std::string, std::vector<TimeMapNode *>> hash_table;

    public:
        TimeMap() {
            
        }
        
        void set(std::string key, std::string value, int timestamp) {
            // if key not available in hash_table, initial it.
            if (this->hash_table.find(key) == this->hash_table.end()) {
                std::vector<TimeMapNode *> map_node;
                this->hash_table.insert({key, map_node});
            }

            // get the vector
            std::vector<TimeMapNode *>& map_node = this->hash_table[key];

            if (map_node.size() > 0) {
                // get last_node
                TimeMapNode *last_node = map_node[map_node.size() - 1];
                
                // if set timestamp < last_node->timestamp, just return
                if (last_node->timestamp >= timestamp) {
                    return;
                }
            }

            // create new node, then push_back, and update hash_table
            TimeMapNode *node = new TimeMapNode(key, value, timestamp);
            map_node.push_back(node);
        }
        
        std::string get(std::string key, int timestamp) {
            // simple edge case handle
            if (this->hash_table.find(key) == this->hash_table.end()) {
                return "";
            }
            
            const std::vector<TimeMapNode *>& node_list = this->hash_table[key];

            if (node_list[0]->timestamp > timestamp) { // edge case, if timestamp < node_list[0]->timestamp, return ""
                return "";
            } else if (node_list.size() > 0 && node_list[node_list.size() - 1]->timestamp <= timestamp) {   // edge case, if timestamp > node_list[node_list.size() - 1] -> timestamp, return last_node->value
                return node_list[node_list.size() - 1]->value;
            }

            int high = node_list.size() - 1;
            int low = 0;

            while (low < high) {
                int mid = low + (high - low + 1) / 2;
                if (node_list[mid]->timestamp > timestamp) {
                    high = mid - 1;
                } else {
                    low = mid;
                }
            }
            
            return node_list[low]->value;
        }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */