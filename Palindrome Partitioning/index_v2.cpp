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


class Solution {
    private:
        bool is_palindrome(std::string s) {
            int s_length = s.size();
            int index_length = s_length / 2;
            bool r = true;
            for (int i = 0, j = s_length - 1; i < index_length; i++, j--) {
                if (s[i] != s[j]) {
                    r = false;
                    break;
                }
            }

            return r;
        }

        // [["a","a","b","c","c"],["a","a","b","cc"],["aa","b","c","c"],["aa","b","cc"]]
        void back_track(std::vector<std::vector<std::string>> &dp, std::string s, int s_size, int index, int offset) {
            if (index >= s_size) {
                return;
            }

            std::vector<std::string> k;

            for (int i = index; i < s_size; i++) {
                std::string r = s.substr(i, offset);
                if (is_palindrome(r) == true) {
                    k.push_back(r);
                }
                
            }
            dp.push_back(k);
            back_track(dp, s, s_size, index, offset + 1);
        }
    public:
        std::vector<std::vector<std::string>> partition(std::string s) {
            std::vector<std::vector<std::string>> dp;
            int s_length = s.size();
            back_track(dp, s, s_length, 0, 1);

            return dp;
        }
};