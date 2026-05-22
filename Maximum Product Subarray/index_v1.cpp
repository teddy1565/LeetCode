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
#include <unordered_set>
#include <charconv>

// 乘法交換律
// 好像跟coin或股票題目有點像
// [5, 7, -2,    5,   -33, 0, -98, 2, -3]
//  5. 35 2     10  11550 0 1  , 2
// -1 -1  35   -350 -165  0 -98, -196
class Solution {
    private:
        void show(std::vector<std::vector<int>> & dp) {
            int n = dp.size();
            for (int i = 0; i < n; i++) {
                std::cout << dp[i][0] << ", ";
            }
            std::cout << std::endl;
            for (int i = 0; i < n; i++) {
                std::cout << dp[i][1] << ", ";
            }
            std::cout << std::endl;
            std::cout << "-----------" << std::endl;
            std::cout << std::endl;
        }
    public:
        int maxProduct(std::vector<int>& nums) {
            int n = nums.size();
            std::vector<std::vector<int>> dp(n + 1, std::vector<int>(2, 0));

            dp[0][0] = 1;
            dp[0][1] = -1;

            for (int i = 0; i < n; i++) {
                show(dp);
                if (nums[i] == 0) {
                    dp[i + 1][0] = 0;
                    dp[i + 1][1] = 0;
                    continue;
                } else if (dp[i][0] == 0) {    // 在這個題目中，會出現零，必定代表另一個也為零
                    dp[i + 1][0] = std::max(1, nums[i]);
                    dp[i + 1][1] = std::min(-1, nums[i]);
                    continue;
                }

                int x = nums[i] * dp[i][0];
                int y = nums[i] * dp[i][1];
                dp[i + 1][0] = std::max(x, y);
                dp[i + 1][1] = std::min(x, y);
                dp[i][0] = 1;
                dp[i][1] = -1;
            }

            show(dp);

            return 0;
        }
};