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
#include <set>
#include <numeric>

// acdcb | a*c?b
// abcde | *a*b*c*d*e*
// abefcdgiescdf | ab*cd?i*f
class Solution {
    public:
        bool isMatch(std::string s, std::string p) {
            int s_size = s.size();
            int p_size = p.size();
            
            int i = 0;
            int j = 0;
            
            int i_star = -1;
            int j_star = -1;

            // O(m * n)
            while (i < s_size) {

                
                if (j < p_size && (s[i] == p[j] || p[j] == '?')) {
                    ++i;
                    ++j;
                } else if (j < p_size && p[j] == '*') {
                    // 如果遇到*符號，紀錄當下的i跟j位置，並且j遞增
                    i_star = i;
                    j_star = j;

                    j += 1;
                } else if (i_star >= 0) {
                    i_star += 1;
                    i = i_star;
                    j = j_star + 1;
                } else {
                    return false;
                }
            }

            while (j < p_size && p[j] == '*') {
                j += 1;
            }

            return j == p_size;
        }
};