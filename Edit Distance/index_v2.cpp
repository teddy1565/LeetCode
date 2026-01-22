#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>

/**
 * @brief 
 * 
 * Example 1:

Input: word1 = "horse", word2 = "ros"
Output: 3
Explanation: 
horse -> rorse (replace 'h' with 'r')
rorse -> rose (remove 'r')
rose -> ros (remove 'e')
Example 2:

Input: word1 = "intention", word2 = "execution"
Output: 5
Explanation: 
intention -> inention (remove 't')
inention -> enention (replace 'i' with 'e')
enention -> exention (replace 'n' with 'x')
exention -> exection (replace 'n' with 'c')
exection -> execution (insert 'u')
 * 
 */

 /**
 * w1 "intention"
 * w2 "zxy"
 * 
 * dp[0][0] = 0
 * dp[0][1] = 1   // because insert
 * dp[0][2] = 2   // because insert
 * dp[0][3] = 3   // because insert
 * 
 * dp[1][0] = 1   // because insert
 * dp[1][1] = 1   // becuase replace
 * 
 * 
 *    #  i  n  t  e  n  t  i  o  n
 * #  0  1  2  3  4  5  6  7  8  9
 * z  1  1  2  3  4  5  6  7  8  9
 * x  2  2  2  3  4  5  6  7  8  9 
 * y  3  3  3  3  4  5  6  7  8  9
 */
class Solution {
    public:
        int minDistance(std::string word1, std::string word2) {
            int word1_size = word1.size();
            int word2_size = word2.size();
            // dp[i][j] means word1[0 ~ i] transfer to word2[0 ~ j] need how many steps
            std::vector<std::vector<int>> dp(word1_size + 1, std::vector<int>(word2_size + 1, 0));

            // initial 
            for (int i = 0; i <= word1_size; i++) {
                dp[i][0] = i;
            }

            // inital
            for (int i = 0; i <= word2_size; i++) {
                dp[0][i] = i;
            }

            for (int i = 1; i <= word1_size; i++) {
                for (int j = 1; j <= word2_size; j++) {
                    if (word1[i - 1] == word2[j - 1]) {
                        dp[i][j] = dp[i - 1][j - 1];
                    } else {
                        dp[i][j] = std::min(dp[i - 1][j - 1], std::min(dp[i - 1][j], dp[i][j - 1])) + 1;
                    }
                }
            }

            return dp[word1_size][word2_size];
        }
};

