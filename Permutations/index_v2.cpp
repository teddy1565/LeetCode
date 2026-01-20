#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>


class Solution {
    private:
        void backtrack(std::vector<std::vector<int>>& result, std::vector<int>& nums, int nums_size, int index) {
            if (index >= nums_size) {
                result.push_back(nums);
                return;
            }

            for (int i = index; i < nums_size; i++) {
                std::swap(nums[i], nums[index]);
                this->backtrack(result, nums, nums_size, index + 1);
                std::swap(nums[i], nums[index]);
            }

        }
    public:
        std::vector<std::vector<int>> permute(std::vector<int>& nums) {
            int n = nums.size();
            std::vector<std::vector<int>> ans;
            int index = 0;
            this->backtrack(ans, nums, n, index);
            return ans;
        }
};