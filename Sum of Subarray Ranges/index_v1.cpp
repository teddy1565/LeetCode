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
        long long ranges_helper(std::vector<int>& nums) {

        }
    public:
        long long subArrayRanges(std::vector<int>& nums) {
            int nums_size = nums.size();
            long long int minimum = nums[0];
            long long int maximum = nums[0];
            long long int ranges = 0;
            std::unordered_map<int, int> count_map;

            for (int i = 0; i < nums_size; i++) {
                if (count_map.find(nums[i]) == count_map.end()) {
                    count_map[nums[i]] = 0;
                }
                count_map[nums[i]] += 1;

                if (nums[i] < minimum) {
                    minimum = nums[i];
                } else if (nums[i] > maximum) {
                    maximum = nums[i];
                }
            }
            
            for (int i = 0, j = nums_size - 1; i <= j; i++, j--) {
                ranges += (maximum - minimum);
                for (int x = 0; x < i; x++) {
                    
                }
            }
            
        }
};