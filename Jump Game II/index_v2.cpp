#include <vector>
#include <string>
#include <iostream>
#include <list>
#include <unordered_map>
#include <algorithm>

/**
 * @brief Greedy
 * 
 */

class Solution {
    public:
        int jump(std::vector<int>& nums) {

            if (nums.size() < 2) {
                return 0;
            }

            int current_end = 0;    // current you can touch index
            int max_jump_size = 0;  // max jump size
            int jumps = 0;  // jump step count

            for (int i = 0; i < nums.size() - 1; i++) {
                max_jump_size = std::max(max_jump_size, i + nums[i]);
                if (i == current_end) {
                    jumps += 1;
                    current_end = max_jump_size;
                }
                if (current_end >= nums.size() - 1) {
                    break;
                }
            }

            return jumps;
        }
};