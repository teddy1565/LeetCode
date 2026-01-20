#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>

/**
 * @brief DP solution
 * 
 */

class Solution {
    public:
        int jump(std::vector<int>& nums) {
            std::vector<int> dp(nums.size(), INT_MAX);
            dp[0] = 0;
            
            for (int i = 0; i < nums.size() - 1; i++) {
                int nums_end = i + nums[i];
                
                for (int j = i + 1; j <= nums_end && j < nums.size(); j++) {
                    dp[j] = std::min(dp[i] + 1, dp[j]);
                }
                if (nums_end == nums.size() - 1) {
                    break;
                }
            }

            return dp[nums.size() - 1];
        }
};