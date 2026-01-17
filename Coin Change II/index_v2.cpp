#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <map>

class Solution {
    public:
        int change(int amount, std::vector<int>& coins) {
            std::vector<unsigned int> dp(amount + 1, 0);
            
            dp[0] = 1;

            for (int i = 0; i < coins.size(); i++) {
                for (int j = coins[i]; j <= amount; j++) {
                    dp[j] += dp[j - coins[i]];
                }
            }

            return (int)dp[amount];
        }
};