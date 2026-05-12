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
#include <set>
#include <numeric>

// aaad
// aaa d
// aaa
class Solution {
    public:
        static int countSubstrings(std::string s) {
            if (s.empty()) {
                return 0;
            }
            
            int n = s.size();
            int ans = 0;
            std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));

            for (int i = n - 1; i >= 0; i--) {
                for (int j = i; j < n; j++) {
                    dp[i][j] = (s[i] == s[j]) && (j - i <= 2 || dp[i + 1][j - 1]);
                    if (dp[i][j]) {
                        ans += 1;
                    }
                }
            }

            return ans;
        }
};