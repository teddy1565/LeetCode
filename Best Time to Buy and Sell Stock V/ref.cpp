#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    long long maximumProfit(vector<int>& prices, int k) {
        int n = prices.size();
      
        // Dynamic programming array
        // dp[day][transactions][state]
        // state 0: no stock held
        // state 1: holding stock (bought)
        // state 2: sold stock (with profit tracking)
        long long dp[n][k + 1][3];
        memset(dp, 0, sizeof(dp));
      
        // Initialize first day states for all transaction counts
        for (int j = 1; j <= k; ++j) {
            // Buying stock on day 0 costs prices[0]
            dp[0][j][1] = -prices[0];
            // This state represents selling, initialized to prices[0]
            dp[0][j][2] = prices[0];
        }
      
        // Fill the DP table for each day
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= k; ++j) {
                // State 0: Not holding stock
                // Can come from: staying without stock, selling from state 1, or buying from state 2
                dp[i][j][0] = max({dp[i - 1][j][0], 
                                   dp[i - 1][j][1] + prices[i], 
                                   dp[i - 1][j][2] - prices[i]});
              
                // State 1: Holding stock
                // Can come from: keeping the stock, or buying (using one transaction)
                dp[i][j][1] = max(dp[i - 1][j][1], 
                                  dp[i - 1][j - 1][0] - prices[i]);
              
                // State 2: Special selling state
                // Can come from: staying in this state, or selling (using one transaction)
                dp[i][j][2] = max(dp[i - 1][j][2], 
                                  dp[i - 1][j - 1][0] + prices[i]);
            }
        }
      
        // Return maximum profit with at most k transactions, ending without stock
        return dp[n - 1][k][0];
    }
};