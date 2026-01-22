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
            std::vector<int> dp(m, 1);  // Space O(m)

            for (int i = 1; i < n; i++) {   // O(n * m)
                for (int j = 1; j < m; j++) {
                    dp[j] = dp[j - 1] + dp[j];
                }
            }

            return dp[m - 1];
        }
};