#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>

class Trie {
    private:
        struct TrieNode {
            int chr_list[26] = { 0 };
            struct TrieNode *next;
            
            TrieNode() {
                this->next = nullptr;
            }
        };

        std::vector<TrieNode *> trie_node_root;

    public:
        Trie() {
            for (int i = 0; i < 26; i++) {
                this->trie_node_root.push_back(nullptr);
            }
        }
        
        void insert(std::string word) {
            int word_size = word.size();
            if (search(word) == true) {
                return;
            }
            TrieNode *head = this->trie_node_root[word[0]-'a'];
            if (head == nullptr) {
                head = new TrieNode();
                this->trie_node_root[word[0] - 'a'] = head;
            }
            TrieNode *p = head;
            for (int i = 1; i < word_size; i++) {
                p->chr_list[word[0] - 'a'] += 1;
                if (p->next == nullptr) {
                    p->next = new TrieNode();
                }
                p = p->next;
            }
        }
        
        bool search(std::string word) {
            int word_size = word.size();
            TrieNode *head = this->trie_node_root[word[0]-'a'];
            if (head == nullptr) {
                return false;
            }
            TrieNode *p = head;
            bool result = true;

            for (int i = 1; i < word_size; i++) {
                if (p == nullptr) {
                    result = false;
                    break;
                } else if (p->chr_list[word[0] - 'a'] == 0) {
                    result = false;
                    break;
                } else if (p->chr_list[word[0] - 'a'] > 0) {
                    p = p->next;
                }
            }
            return result;
        }
        
        bool startsWith(std::string prefix) {
            int word_size = prefix.size();
            TrieNode *head = this->trie_node_root[prefix[0]-'a'];
            if (head == nullptr) {
                return false;
            }
            TrieNode *p = head;
            bool result = true;

            for (int i = 1; i < word_size; i++) {
                if (p == nullptr) {
                    result = false;
                    break;
                } else if (p->chr_list[prefix[0] - 'a'] == 0) {
                    result = false;
                    break;
                } else if (p->chr_list[prefix[0] - 'a'] > 0) {
                    p = p->next;
                }
            }
            return result;
        }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */