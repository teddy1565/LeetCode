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

            // define an array record s1 string each char count
            std::vector<int> s1_char_count(26, 0);
            
            // declare an array record s2 string each char count
            std::vector<int> s2_char_count(26, 0);

            

            // initial
            for (int i = 0; i < s1_size; i++) {
                int n = s1[i] - 'a';
                int m = s2[i] - 'a';
                s1_char_count[n] += 1;
                s2_char_count[m] += 1;
            }
            
            if (s1_char_count == s2_char_count) {
                return true;
            }

            // set a slice window for s2_char_count, when s2 push back a char index, remove first record, then compare memory
            // if sames, means s1 is permutation in s2

            for (int i = s1_size; i < s2_size; i++) {
                int head_index = s2[i - s1_size] - 'a';
                s2_char_count[head_index] -= 1;

                int k = s2[i] - 'a';
                s2_char_count[k] += 1;

                if (s2_char_count == s1_char_count) {
                    return true;
                }
                
            }
            
            return false;
        }
};