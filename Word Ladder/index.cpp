#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>


class Solution {

    private:
        


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
            std::unordered_map<std::string, bool> used_map;
            std::unordered_map<std::string, std::vector<char>> word_map;

            int ans = 0;
            std::queue<std::string> bfs_queue;
            std::queue<int> stack_queue;

            used_map[beginWord] = false;

            for (int i = 0; i < wordList.size(); i++) {
                used_map[wordList[i]] = false;
            }
            
            for (int i = 0; i < wordList.size(); i++) {
                for (int j = 0; j < beginWord.size(); j++) {
                    std::string tmp(wordList[i]);
                    char k = tmp[j];
                    tmp[j] = '-';

                    if (word_map.find(tmp) == word_map.end()) {
                        std::vector<char> dic;
                        word_map.insert({tmp, dic});
                    }
                    std::vector<char>& v = word_map[tmp];
                    v.push_back(k);
                }
            }

            
            
            bfs_queue.push(beginWord);
            stack_queue.push(1);
            

            while(bfs_queue.size() > 0) {
                std::string begin_word = bfs_queue.front();
                bfs_queue.pop();

                int stack_i = stack_queue.front();
                stack_queue.pop();

                if (begin_word == endWord) {
                    ans = stack_i;
                    break;
                } else if (used_map[begin_word] == true) {
                    continue;
                }

                used_map[begin_word] = true;

                for (int i = 0; i < begin_word.size(); i++) {
                    std::string begin_word_tmp(begin_word);
                    begin_word_tmp[i] = '-';
                    
                    std::vector<char>& word_list = word_map[begin_word_tmp];
                    for (int j = 0; j < word_list.size(); j++) {
                        char k = word_list[j];
                        begin_word_tmp[i] = k;
                        if (used_map[begin_word_tmp] == true) {
                            continue;
                        }
                        bfs_queue.push(begin_word_tmp);
                        stack_queue.push(stack_i + 1);
                    }
                }
            }

            return ans;
        }
};
