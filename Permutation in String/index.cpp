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

            // Initialize frequency vectors for s1 and the first window of s2
            std::vector<int> s1_char_count(26, 0);
            std::vector<int> s2_char_count(26, 0);

            

            // Compute character counts for the first window
            for (int i = 0; i < s1_size; i++) {
                int n = s1[i] - 'a';
                int m = s2[i] - 'a';
                s1_char_count[n] += 1;
                s2_char_count[m] += 1;
            }
            
            if (s1_char_count == s2_char_count) {
                return true;
            }

            // Slide the window over s2
            // Add the new character into the window and remove the old character from the left
            for (int i = s1_size; i < s2_size; i++) {
                // Remove the character leaving the window
                int head_index = s2[i - s1_size] - 'a';
                s2_char_count[head_index] -= 1;

                // Add the new character entering the window
                int k = s2[i] - 'a';
                s2_char_count[k] += 1;

                // Check if the current window matches s1's frequency
                if (s2_char_count == s1_char_count) {
                    return true;
                }
                
            }
            
            return false;
        }
};