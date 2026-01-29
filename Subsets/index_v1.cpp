#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>

class Solution {
    private:
        void back_tracking(std::vector<std::vector<int>>& answer, std::vector<int>& current_nums, std::vector<int>& nums, int index) {
            if (index > nums.size()) {
                return;
            }

            
            answer.push_back(current_nums);

            for (int i = index; i < nums.size(); i++) {
                current_nums.push_back(nums[i]);
                back_tracking(answer, current_nums, nums, i + 1);
                current_nums.pop_back();
            }
        }
    public:
        std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
            std::vector<std::vector<int>> answer;
            std::vector<int> current_nums;

            back_tracking(answer, current_nums, nums, 0);
            return answer;
        }
};