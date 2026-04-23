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
            int i = 0;
            int j = 0;
            int i_star = -1;
            int j_star = -1;

            int s_size = s.size();
            int p_size = p.size();

            while (i < s_size) {
                if (j < p_size && (s[i] == p[j] || p[j] == '?')) {
                    ++i;
                    ++j;
                } else if (j < p_size && p[j] == '*') {
                    i_star = i;
                    j_star = j++;
                } else if (i_star >= 0) {
                    i = ++i_star;
                    j = j_star + 1;
                } else {
                    return false;
                }
            }

            while (j < p_size && p[j] == '*') {
                ++j;
            }

            return j == p_size;
        }
};