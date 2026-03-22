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
 

/**
 * @brief 
 * 參考CSV檔案，以row的數量對應source string, col的數量對應target string
 * 
 * dp[x][y] 代表的是，如果target[y]可以匹配source[x]，那麼它所儲存的數值，所代表的含意是
 * 
 * 到dp[x][y]這個可能性為止，當前的source[x]與target[y]可以被匹配多少次?
 * 
 * 如果可以被匹配，那麼繼承前一個字元的可能性 + 自己到目前為止的可能性
 * 如果不能被匹配，直接繼承前一次匹配的可能性數量
 */


class Solution {

    public:
        static int numDistinct(std::string s, std::string t) {
            if (s.size() < t.size()) {
                return 0;
            }

            unsigned int source_size = s.size();
            unsigned int target_size = t.size();
            std::vector<std::vector<unsigned int>> dp(source_size + 1, std::vector<unsigned int>(target_size + 1, 0));
            
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

            return dp[source_size][target_size];
        }
};