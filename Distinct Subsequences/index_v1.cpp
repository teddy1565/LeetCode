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

// Given two strings s and t, return the number of distinct subsequences of s which equals t.
// The test cases are generated so that the answer fits on a 32-bit signed integer.

// Example 1:
//      Input: s = "rabbbit", t = "rabbit"
//      Output: 3
//      Explanation:
//      As shown below, there are 3 ways you can generate "rabbit" from s.
//      rabb it
//      rab bit
//      ra bbit


// Example 2:
//      Input: s = "babgbag", t = "bag"
//      Output: 5
//      Explanation:
//      As shown below, there are 5 ways you can generate "bag" from s.
//      ba g   
//      ba    g
//      b    ag
//        b  ag
//          bag
 
class Solution {

    private:
        void show_table(std::vector<std::vector<int>> & dp) {
            for (int i = 0; i < dp.size(); i++) {
                for (int j = 0; j < dp[i].size(); j++) {
                    std::cout << dp[i][j] << ", ";
                }
                std::cout << std::endl;
            }

            std::cout << "------------" << std::endl;
        }
    public:
        int numDistinct(std::string s, std::string t) {
            if (s.size() < t.size()) {
                return 0;
            }
            int source_size = s.size();
            int target_size = t.size();
            std::vector<std::vector<int>> dp(source_size + 1, std::vector<int>(target_size + 1, 0));
            
            for (int i = 0; i <= source_size; i++) {
                dp[i][0] = 1;
            }

            for (int i = 1; i <= source_size; i++) {
                for (int j = 1; j <= target_size; j++) {
                    if (t[j - 1] == s[i - 1]) {
                        dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                    } else {
                        dp[i][j] = dp[i - 1][j];
                    }
                }
            }

            show_table(dp);

            return dp[source_size][target_size];
        }
};