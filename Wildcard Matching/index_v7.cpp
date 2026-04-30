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
            int source_size = s.size();
            int pattern_size = p.size();
            
            int i = 0;
            int j = 0;
            
            int i_star = -1;
            int j_star = -1;
            
            while (i < source_size) {
                if (j < pattern_size && (s[i] == p[j] || p[j] == '?')) {
                    i += 1;
                    j += 1;
                } else if (j < pattern_size && p[j] == '*') {
                    i_star = i;
                    j_star = j;
                    j += 1;
                } else if (i_star >= 0) {
                    i_star += 1;
                    // 從上一個i_star + 1位置開始搜尋
                    i = i_star;
                    j = j_star + 1;
                } else {
                    return false;
                }
            }

            while (j < pattern_size && p[j] == '*') {
                j += 1;
            }

            return j == pattern_size;
        }
};