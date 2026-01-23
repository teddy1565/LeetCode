#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>

/**
 * @brief [4,-2,-3,4,1]
 *         n    m
 *         x         y 
 * 
 *         x       y
 *         i x       y
 */
class Solution {

    public:
        long long subArrayRanges(std::vector<int>& nums) {
            int nums_size = nums.size();
            std::vector<std::vector<int>> dp(nums_size + 1, std::vector<int>(nums_size + 1, 0));

            for (int i = 1; i < nums_size; i++) {
                int miximum = nums[i];
                int minimum = INT_MAX;
                for (int j = 1; j <= i; j++) {
                    miximum = std::max(nums[j - 1], miximum);
                    minimum = std::min(nums[j - 1], minimum);
                    dp[i][j] = (miximum - minimum) + std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }

            for (int i = 0; i < nums_size; i++) {
                for (int j = 0; j < nums_size; j++) {
                    std::cout << dp[i][j] << ", ";
                }

                std::cout << std::endl;
            }
            
            return 0;
        }
};