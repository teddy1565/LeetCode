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
        void back_track(std::vector<std::vector<std::string>> &dp, std::string s, int s_size, std::string r, std::vector<std::string> &k, int index) {
            if (index >= s_size) {
                return;
            }

            if (r.size() > 0) {
                r.pop_back();
            }

            for (int i = index; i < s_size; i++) {
                r.append(1, s[i]);
                back_track(dp, s, s_size, r, k, index + 1);
                if (is_palindrome(r) == true) {
                    k.push_back(r);
                }
                
                std::cout << k.size() << std::endl;
                k.clear();
            }
        }
    public:
        std::vector<std::vector<std::string>> partition(std::string s) {
            std::vector<std::vector<std::string>> dp;
            int s_length = s.size();

            std::string r;
            std::vector<std::string> k;
            back_track(dp, s, s_length, r, k, 0);

            return dp;
        }
};