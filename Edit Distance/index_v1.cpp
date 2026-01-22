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
class Solution {
    public:
        int minDistance(std::string word1, std::string word2) {

            int dp_size = word1.size() > word2.size() ? (word2.size() + 1): (word1.size() + 1);
            /**
             * @brief 
             * 1. remove
             * 2. replace
             * 3. insert
             */
            // declare a dp vector
            std::vector<int> dp(dp_size, 0);
            
            int scan_index = 0;

            for (int i = 1; i < dp_size; i++) {
                bool find_same = false;
                for (int j = scan_index; j < i && find_same == false; j++) {
                    for (int k = scan_index; k < i; k++) {
                        if (word1[j] == word2[k]) {
                            find_same = true;
                            scan_index = j > k ? (j + 1) : (k + 1);
                            break;
                        }
                    }
                    if (find_same == true) {
                        break;
                    }
                }
                if (find_same == true) {
                    dp[i] = dp[i - 1];
                } else {
                    dp[i] = dp[i - 1] + 1;
                }
            }

            std::cout << dp[dp_size - 1] << std::endl;

            return 0;
        }
};


/**
 * @brief 
 * w1 "intention"
 * w2 "extioneee"
 *     122344567
 *     122345567
 * 
 * 1, 1| w1[0] -> replace or remove + 1, w2[0] -> replace or remove +1
 * 2, 2| w1[1] -> replace or remove + 1, w2[1] -> replace or remove + 1
 * 2, 2| w1[2] -> sames, doesn't change, w2[2] -> sames, doesn't chage
 * 3, 3| w1[3] -> scan from w2[2 + 1] to [3], replace or remove +1, w2[3] -> scan from w1[2 + 1] to [3], replace or remove + 1
 * 4, 4| w1[4] -> scan from w2[2 + 1] to [4], replace or  remove + 1, w2[4] -> scan from w1[2 +１]　to [4], replace or remove or insert + 1
 * 5, 4| w1[5] -> scan from w2[2 + 1] to [5], replace or remove + 1, w2[5] -> scan from w1[2+ 1] to [5], same
 */

/**
 * @brief 
 * w1 "intention"
 * w2 "executions"
 *     12345
 */
/**
 * w1 "intention"
 * w2 "zxy"
 *     123
 */