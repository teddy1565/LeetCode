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

class Node {
    public:
        int val;
        std::vector<Node*> neighbors;
        Node() {
            val = 0;
            neighbors = std::vector<Node*>();
        }
        Node(int _val) {
            val = _val;
            neighbors = std::vector<Node*>();
        }
        Node(int _val, std::vector<Node*> _neighbors) {
            val = _val;
            neighbors = _neighbors;
        }
};

class Solution {
    private:
        std::unordered_map<Node *, Node *> replaced_map;
    public:
        Node* cloneGraph(Node* node) {
            if (node == nullptr) {
                return node;
            }
            if (this->replaced_map.find(node) != this->replaced_map.end()) {
                return this->replaced_map[node];
            }

            Node *a = new Node(node->val, node->neighbors);

            this->replaced_map[node] = a;

            int neighbors_size = a->neighbors.size();
            
            for (int i = 0; i < neighbors_size; i++) {
                a->neighbors[i] = cloneGraph(a->neighbors[i]);
            }
            return a;
        }
};