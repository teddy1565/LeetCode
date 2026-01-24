#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>



class Solution {
    public:
        static std::string minWindow(std::string s, std::string t) {
            if (t.size() > s.size()) {
                return "";
            }

            int left = 0;
            int right = 0;
            int count = 0;
            int minimum_str_size = INT_MAX;
            int answer_str_start_index = -1;
            
            std::vector<int> hash_map(256, 0);

            for (int i = 0; i < t.size(); i++) {
                hash_map[t[i]] += 1;
                count += 1;
            }

            while (right < s.size()) {
                if (hash_map[s[right]] > 0) {
                    count -= 1;
                }

                hash_map[s[right]] -= 1;

                while (count == 0) {
                    if (right - left + 1 < minimum_str_size) {
                        minimum_str_size = right - left + 1;
                        answer_str_start_index = left;
                    }

                    hash_map[s[left]] += 1;
                    
                    if (hash_map[s[left]] > 0) {
                        count += 1;
                    }

                    left += 1;
                }

                right += 1;
            }

            return answer_str_start_index == -1 ? "" : s.substr(answer_str_start_index, minimum_str_size);
        }
};
