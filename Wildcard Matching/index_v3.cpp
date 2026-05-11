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
            std::vector<std::vector<bool>> dp(s_size + 1, std::vector<bool>(p_size + 1));
            dp[0][0] = true;
            for (int i = 1; i <= p_size; i++) {
                if (p[i - 1] == '*') {
                    dp[0][i] = dp[0][i - 1];
                }
            }

            for (int i = 1; i <= s_size; i++) {
                for (int j = 1; j <= p_size; j++) {
                    if (p[j - 1] == '*') {
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1];
                    } else {
                        dp[i][j] = (s[i - 1] == p[j - 1] || p[j - 1] == '?') && dp[i - 1][j - 1];
                    }
                }
            }

            return dp[s_size][p_size];
        }
};