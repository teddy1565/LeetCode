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
            int p_size = p.size();
            int s_size = s.size();
            
            std::vector<std::vector<bool>> dp(p_size, std::vector<bool>(s_size, false));

            int i = p_size - 1;
            int j = s_size - 1;
            while (i >= 0 && j >= 0) {
                if (i == 0 && j == 0) {
                    if (p[i] == s[j]) {
                        dp[i][j] = true;
                    } else if (p[i] == '*') {
                        dp[i][j] = true;
                    } else if (p[i] == '?') {
                        dp[i][j] = true;
                    }
                    break;
                }

                if (i == 0 && j > 0) {
                    while (j > 0 && i == 0) {
                        if (p[i] == s[j]) {
                            dp[i][j] = true;
                            j -= 1;
                            i -= 1;
                        } else if (p[i] == '*') {
                            dp[i][j] = true;
                            j -= 1;
                        } else if (p[i] == '?') {
                            dp[i][j] = true;
                            j -= 1;
                            break;
                        } else {
                            return false;
                        }
                    }
                } else if (i > 0 && j == 0) {
                    while (i > 0 && j == 0) {
                        if (p[i] == '*') {
                            dp[i][j] = true;
                            i -= 1;
                        } else if (p[i] == '?') {
                            dp[i][j] = true;
                            i -= 1;
                        } else if (p[i] == s[j]) {
                            dp[i][j] = true;
                            i -= 1;
                        } else if (p[i] != s[j]) {
                            return false;
                        }
                    }
                } else if (p[i] == '*') {
                    dp[i][j] = true;
                    if (p[i - 1] == '?' || p[i - 1] == '*') {
                        i = i - 1;
                    } else {
                        while (j > 0) {
                            dp[i][j] = true;
                            if (s[j] == p[i - 1]) {
                                i -= 1;
                                break;
                            }
                            j -= 1;
                        }
                    }
                } else if (p[i] == '?') {
                    dp[i][j] = true;
                    i -= 1;
                    j -= 1;
                } else if (p[i] == s[j]) {
                    dp[i][j] = true;
                    i -= 1;
                    j -= 1;
                } else {
                    break;
                }
            }

            return dp[0][0];
        }
};