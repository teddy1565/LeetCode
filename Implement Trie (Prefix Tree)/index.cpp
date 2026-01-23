#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>

class Trie {
    private:
        static struct TrieNode {
            bool is_word;

            TrieNode *child[26];
            
            TrieNode() {
                this->is_word = false;
                for (int i = 0; i < 26; i++) {
                    this->child[i] = nullptr;
                }
            }
        };

        TrieNode *root;

    public:
        Trie() {
            this->root = new TrieNode();
        }
        
        void insert(std::string word) {
            TrieNode *p = this->root;
            for (int i = 0; i < word.size(); i++) {
                const int k = word[i] - 'a';
                if (p->child[k] == nullptr) {
                    p->child[k] = new TrieNode();
                }
                p = p->child[k];
            }
            p->is_word = true;
        }
        
        bool search(std::string word) {
            TrieNode *p = this->root;
            for (int i = 0; i < word.size(); i++) {
                const int k = word[i] - 'a';
                if (p->child[k] == nullptr) {
                    return false;
                }
                p = p->child[k];
            }
            return p->is_word;
        }
        
        bool startsWith(std::string prefix) {
            TrieNode *p = this->root;
            for (int i = 0; i < prefix.size(); i++) {
                const int k = prefix[i] - 'a';
                if (p->child[k] == nullptr) {
                    return false;
                }
                p = p->child[k];
            }

            return true;
        }
};