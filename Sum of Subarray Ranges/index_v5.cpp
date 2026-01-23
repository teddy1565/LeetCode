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
        long long int ranges(std::vector<int>& nums, const int nums_size, int index, int maximum, int minimum) {
            long long int result = maximum - minimum;
            if (index == nums_size) {
                return result;
            }

            

            if (nums[index] > maximum) {
                maximum = nums[index];
            } else if (nums[index] < minimum) {
                minimum = nums[index];
            }

            result += ranges(nums, nums_size, index + 1, maximum, minimum);

            return result;
        }
    public:
        long long subArrayRanges(std::vector<int>& nums) {
            int nums_size = nums.size();
            long long int answer = 0;
            for (int i = 0; i < nums_size; i++) {
                int maximum = nums[i];
                int minimum = nums[i];
                answer += this->ranges(nums, nums_size, i, maximum, minimum);
            }

            return answer;
        }
};