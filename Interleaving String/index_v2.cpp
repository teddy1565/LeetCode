#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>

// 需要注意DP，單純使用greedy有些可能性match不到
class Solution {
    private:
        bool can_interleave(std::vector<std::vector<int>>&dp, std::string & s1, std::string & s2, std::string & s3, const int s1_size, const int s2_size, int idx1, int idx2) {
            if (idx1 >= s1_size && idx2 >= s2_size) {
                return true;
            }
            
            if (dp[idx1][idx2] != -1) {
                return dp[idx1][idx2] == 1;
            }

            dp[idx1][idx2] = 0;
            int idx3 = idx1 + idx2;
            
            if (idx1 < s1_size && s1[idx1] == s3[idx3]) {
                if (can_interleave(dp, s1, s2, s3, s1_size, s2_size, idx1 + 1, idx2)) {
                    dp[idx1][idx2] = 1;
                    return true;
                }
            }

            if (idx2 < s2_size && s2[idx2] == s3[idx3]) {
                if (can_interleave(dp, s1, s2, s3, s1_size, s2_size, idx1, idx2 + 1)) {
                    dp[idx1][idx2] = 1;
                    return true;
                }
            }

            return dp[idx1][idx2] == 1;
        }
    public:
        bool isInterleave(std::string s1, std::string s2, std::string s3) {
            int s1_size = s1.size();
            int s2_size = s2.size();
            int s3_size = s3.size();
            if (s1_size + s2_size != s3_size) {
                return false;
            }

            std::vector<std::vector<int>> dp(s1_size + 1, std::vector<int>(s2_size + 1, -1));
            return can_interleave(dp, s1, s2, s3, s1_size, s2_size, 0, 0);
        }
};

