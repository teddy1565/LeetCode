#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>



class Solution {

    private:
        std::unordered_map<std::string, std::vector<std::string>> hash_map;

    public:
        Solution() {

        }
        int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {

            for (int i = 0; i < beginWord.size(); i++) {
                std::string key(beginWord.size(), '-');
                key[i] = beginWord[i];
                std::vector<std::string> bucket;
                this->hash_map.insert({key, bucket});
            }

            for (int i = 0; i < beginWord.size(); i++) {
                std::string key(beginWord.size(), '-');
                key[i] = beginWord[i];

                for (int j = 0; j < wordList.size(); j++) {
                    std::string tmp = wordList[j];
                    tmp[i] = '-';
                    
                    std::vector<std::string>& bucket = this->hash_map[key];
                    bucket.push_back(tmp);
                }
            }

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