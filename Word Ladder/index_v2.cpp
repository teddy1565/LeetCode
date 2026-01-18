#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>


class Solution {

    private:
        std::unordered_map<std::string, std::vector<std::string>> hash_map;
        std::unordered_map<std::string, bool> used_map;

        void update_hashMap(std::string beginWord, std::vector<std::string>& wordList) {
            this->hash_map.clear();

            for (int i = 0; i < beginWord.size(); i++) {
                std::string key(beginWord);
                key[i] = '-';
                std::vector<std::string> bucket;
                this->hash_map.insert({key, bucket});
            }

            for (int i = 0; i < beginWord.size(); i++) {
                std::string key(beginWord);
                key[i] = '-';

                for (int j = 0; j < wordList.size(); j++) {
                    std::string tmp = wordList[j];
                    char k = tmp[i];
                    tmp[i] = '-';

                    if (tmp == key && k != beginWord[i]) {
                        tmp.assign(beginWord.size(), '-');
                        tmp[i] = k;
                        std::vector<std::string>& bucket = this->hash_map[key];
                        bucket.push_back(tmp);
                    }
                }
            }
        }

        bool check_vaild(std::string end_word, std::vector<std::string>& word_list) {
            bool result = false;
            for (int i = 0; i < word_list.size(); i++) {
                if (word_list[i] == end_word) {
                    result = true;
                    break;
                }
            }
            return result;
        }
    public:
        Solution() {

        }
        int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
            if (check_vaild(endWord, wordList) == false) {
                return 0;
            }

            
            this->used_map[beginWord] = false;
            for (int i = 0; i < wordList.size(); i++) {
                if (wordList[i] == beginWord) {
                    continue;
                }
                this->used_map.insert({wordList[i], false});
            }

            int ans = 0;
            
            std::queue<std::string> queue;
            std::queue<int> num_queue;
            queue.push(beginWord);
            num_queue.push(1);
            int max_stack = 0;
            int test_i = 0;

            while(queue.size() > 0) {
                std::string begin_word = queue.front();
                queue.pop();
                int begin_stack = num_queue.front();
                num_queue.pop();
                if (this->used_map[begin_word] == true) {
                    continue;
                }
                
                update_hashMap(begin_word, wordList);
                this->used_map[begin_word] = true;
                if (begin_stack > max_stack) max_stack = begin_stack;

                std::cout << begin_word << std::endl;
                for (int i = 0; i < begin_word.size(); i++) {
                    std::string key(begin_word);
                    key[i] = '-';
                    std::vector<std::string>& bucket = this->hash_map[key];
                    for (int j = 0; j < bucket.size(); j++) {
                        std::string tmp = bucket[j];
                        if (tmp[i] == '-') {
                            continue;
                        }
                        char k = tmp[i];
                        key[i] = k;
                        if (this->used_map[key] == false) {
                            queue.push(key);
                            num_queue.push(begin_stack + 1);
                        }
                    }
                }
            }

            std::cout << max_stack << std::endl;

            for (const auto& [key, value] : this->hash_map) {
                std::cout << "Key: " << key << "\n" << std::endl;
                for (int i = 0; i < value.size(); i++) {
                    std::cout << "\t[" << i << "]: " << value[i] << std::endl;
                }
            }

            for (int i = 0; i < wordList.size(); i++) {
                if (wordList[i] == endWord) {
                    break;
                }
            }

            return 0;
        }
};