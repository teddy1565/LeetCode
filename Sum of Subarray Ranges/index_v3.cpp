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
        long long ranges(std::vector<int>& nums, std::unordered_map<int, int>& count_map, int maximum, int minimum, int start, int end) {
            long long result = maximum - minimum;
            if ((start + 1) <= end) {
                int left = nums[start];
                count_map[left] -= 1;
                if (count_map[left] <= 0) {
                    
                }
            }

            if ((end + 1) >= start) {

            }
        }
    public:
        long long subArrayRanges(std::vector<int>& nums) {
            int nums_size = nums.size();
            int start = 0;
            int end = nums_size - 1;
            int maximum = nums[0];
            int minimum = nums[0];

            std::unordered_map<int, int> count_map;
            

            for (int i = 0; i < nums_size; i++) {
                if (nums[i] > maximum) {
                    maximum = nums[i];
                } else if (nums[i] < minimum) {
                    minimum = nums[i];
                }
                if (count_map.find(nums[i]) == count_map.end()) {
                    count_map[nums[i]] = 0;
                }
                count_map[nums[i]] += 1;
            }

            return this->ranges(nums, count_map, maximum, minimum, start, end);
        }
};