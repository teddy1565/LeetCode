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
// [2,3,-2,4]
// [-2,0,-1]

// 突然不知道為什麼想通了

class Solution {
    public:
        int maxProduct(std::vector<int>& nums) {
            int n = nums.size();
            int ans = nums[0];
            std::vector<std::array<int, 2>> dp(n, std::array<int, 2>());
            dp[0][0] = nums[0];
            dp[0][1] = nums[0];
            for (int i = 1; i < n; i++) {
                // 記住當下最大值，因為乘法有交換律，所以要不就是自己最大，不然就是乘上[i - 1][0] 或是乘上[i - 1][1]
                dp[i][0] = std::max(nums[i], std::max(nums[i] * dp[i - 1][0], nums[i] * dp[i - 1][1]));

                // 記住當下最小值，因為乘法有交換律，所以最小值，要不是自己，就是自己乘上之前的可能性（前面的可能有有可能是負數，或自己就是負數）
                dp[i][1] = std::min(nums[i], std::min(nums[i] * dp[i - 1][0], nums[i] * dp[i - 1][1]));

                // 全局記憶最大數值
                ans = std::max(ans, std::max(dp[i][0], dp[i][1]));
            }

            return ans;
        }
};