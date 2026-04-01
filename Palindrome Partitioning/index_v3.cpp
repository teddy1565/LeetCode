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
        static bool is_palindrome(std::string &s) {
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

        static void back_track(std::vector<std::vector<std::string>> &dp, std::string &s, int s_size, int index, std::vector<std::string> &k) {
            if (index >= s_size) {
                dp.push_back(k);
                return;
            }

            for (int i = 0; i < s_size; i++) {
                std::string r = s.substr(index, i + 1);
                if (is_palindrome(r) == true) {
                    k.push_back(r);
                    back_track(dp, s, s_size, index + (i + 1), k);
                    k.pop_back();
                    if (index + (i + 1) >= s_size) {
                        break;
                    }
                }
            }
        }
    public:
        std::vector<std::vector<std::string>> partition(std::string s) {
            std::vector<std::vector<std::string>> dp;
            int s_length = s.size();
            std::vector<std::string> k;
            back_track(dp, s, s_length, 0, k);
            return dp;
        }
};