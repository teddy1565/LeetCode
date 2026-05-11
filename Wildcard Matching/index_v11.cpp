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
            int source_length = s.size();
            int pattern_length = p.size();
            int i = 0;
            int j = 0;
            int i_star = -1;
            int j_star = -1;
            while (i < source_length) {
                if (j < pattern_length && (s[i] == p[j] || p[j] == '?')) {
                    i += 1;
                    j += 1;
                } else if (j < pattern_length && p[j] == '*') {
                    i_star = i;
                    j_star = j;
                    j += 1;
                } else if (i_star > -1) {
                    j = j_star + 1;
                    i_star += 1;
                    i = i_star;
                } else {
                    return false;
                }
            }

            while (j < pattern_length && p[j] == '*') {
                j += 1;
            }

            return j == pattern_length;
        }
};