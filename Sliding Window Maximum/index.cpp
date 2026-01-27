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
    public:
        std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
            std::vector<int> answer;
            std::deque<int> nums_queue;
            int left = 0;
            int right = 0;
            int nums_size = nums.size();

            while (right < nums_size) {
                while (!nums_queue.empty() && nums[nums_queue.back()] < nums[right]) {
                    nums_queue.pop_back();
                }

                nums_queue.push_back(right);

                if (left > nums_queue.front()) {
                    nums_queue.pop_front();
                }

                if (right + 1 >= k) {
                    answer.push_back(nums[nums_queue.front()]);
                    left += 1;
                }

                right += 1;

            }
            return answer;
        }
};