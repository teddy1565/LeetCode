#include <vector>
#include <iostream>


class Solution {
    public:
        int firstMissingPositive(std::vector<int>& nums) {

            int num_length = nums.size();
            int min_num = 1;
            for (int i = 0; i < nums.size(); i++) {
                while (nums[i] > 0 && nums[i] <= num_length && nums[nums[i] - 1] != nums[i]) {
                    std::swap(nums[nums[i] - 1], nums[i]);
                }
            }

            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] != min_num) {
                    return min_num;
                }
                min_num += 1;
            }

            return min_num;
        }
};