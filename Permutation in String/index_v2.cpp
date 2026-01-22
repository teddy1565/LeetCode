#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>


class Solution {
    public:
        bool checkInclusion(std::string s1, std::string s2) {
            if (s1.size() > s2.size()) {
                return false;
            }

            int s1_size = s1.size();
            int s2_size = s2.size();
            int diff_count = 0;
            
            std::vector<int> count_map(26, 0);

            

            // initial
            for (int i = 0; i < s1_size; i++) {

                count_map[s1[i] - 'a'] -= 1;
                count_map[s2[i] - 'a'] += 1;

            }

            for (int i = 0; i < 26; i++) {
                if (count_map[i] != 0) {
                    diff_count += 1;
                }
            }
            
            if (diff_count == 0) {
                return true;
            }

            // set a slice window for s2_char_count, when s2 push back a char index, remove first record, then compare memory
            // if sames, means s1 is permutation in s2

            for (int i = s1_size; i < s2_size; i++) {

                int left = s2[i - s1_size] - 'a';
                int right = s2[i] - 'a';

                if (count_map[right] == 0) {
                    diff_count += 1;
                }
                count_map[right] += 1;
                if (count_map[right] == 0) {
                    diff_count -= 1;
                }

                if (count_map[left] == 0) {
                    diff_count += 1;
                }
                count_map[left] -= 1;
                if (count_map[left] == 0) {
                    diff_count -= 1;
                }

                if (diff_count == 0) {
                    return true;
                }
            }
            
            return false;
        }
};