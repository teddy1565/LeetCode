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

    private:
        int helper(std::string & s, std::string & p, int i, int j) {
            if (i == s.size() && j == p.size()) {
                return 2;
            }

            if (i == s.size() && p[j] != '*') {
                return 0;
            }

            if (j == p.size()) {
                return 1;
            }

            if (s[i] == p[j] || p[j] == '?') {
                return helper(s, p, i + 1, j + 1);
            }

            if (p[j] == '*') {
                if (j + 1 < p.size() && p[j + 1] == '*') {
                    return helper(s, p, i, j + 1);
                }

                for (int k = 0; k <= s.size() - i; k++) {
                    int res = helper(s, p, i + k, j + 1);
                    if (res == 0 || res == 2) {
                        return res;
                    }
                }
            }

            return 1;
        }
    public:
        bool isMatch(std::string s, std::string p) {
            return helper(s, p, 0, 0) > 1;
        }
};