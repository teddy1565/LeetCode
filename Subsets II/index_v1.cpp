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
        void back_tracking(std::vector<std::vector<int>>& answer, std::vector<int>& result, std::vector<int>& nums, int index) {
            if (index > nums.size()) {
                return;
            }

            answer.push_back(result);
            
            for (int i = index; i < nums.size(); i++) {
                if (i > index && nums[i] == nums[i - 1]) {
                    continue;
                }
                result.push_back(nums[i]);
                back_tracking(answer, result, nums, i + 1);
                result.pop_back();
            }
            
        }
    public:
        std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
            std::sort(nums.begin(), nums.end());
            std::vector<std::vector<int>> answer;
            std::vector<int> result;


            back_tracking(answer, result, nums, 0);

            return answer;
        }
};
