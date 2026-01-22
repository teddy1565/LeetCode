#include <string>
#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <unordered_map>
#include <queue>


class Solution {
    public:
        int uniquePaths(int m, int n) {
            std::vector<std::vector<int>> dp(m, std::vector<int>(n, 0)); // Space O(n * m)

            for (int i = 0; i < m; i++) {   // O(n)
                dp[i][0] = 1;
            }
            for (int i = 0; i < n; i++) {   // O(n)
                dp[0][i] = 1;
            }
            for (int i = 1; i < m; i++) {   // O(n * m)
                for (int j = 1; j < n; j++) {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }

            return dp[m - 1][n - 1];
        }
};