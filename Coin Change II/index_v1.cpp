#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>

class Solution {
    public:
        int change(int amount, std::vector<int>& coins) {
            std::vector<std::vector<int>> dp(coins.size() + 1, std::vector<int>(amount + 1, 0));
            
            dp[0][0] = 1;

            for (int i = 1; i <= coins.size(); i++) {
                dp[i][0] = 1;
                for (int j = 1; j <= amount; j++) {
                    int k = j >= coins[i - 1] ? dp[i][j - coins[i - 1]] : 0;
                    unsigned int n = (unsigned int) dp[i - 1][j] + (unsigned int) k;
                    dp[i][j] = (int)n;
                }
            }

            return dp[coins.size()][amount];
        }
};