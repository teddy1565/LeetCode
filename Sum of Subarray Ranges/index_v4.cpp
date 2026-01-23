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
    private:
    public:
        long long subArrayRanges(std::vector<int>& nums) {
            int nums_size = nums.size();
            long long int answer = 0;
            for (int i = 0; i < nums_size; i++) {
                int maximum = nums[i];
                int minimum = nums[i];
                for (int j = 0; j < i; j++) {
                    maximum = std::max(nums[j], maximum);
                    minimum = std::min(nums[j], minimum);
                    answer += (long long int) maximum - (long long int) minimum;
                }
            }

            return answer;
        }
};