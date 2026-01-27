#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>

class Solution {
    public:
        std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
            std::vector<int> answer;
            
            std::queue<int> monotonic_decreasing_queue;

            for (int i = 0; i < k; i++) {
                if (monotonic_decreasing_queue.empty()) {
                    monotonic_decreasing_queue.push(nums[i]);
                } else if (nums[i] <= monotonic_decreasing_queue.front()) {
                    monotonic_decreasing_queue.push(nums[i]);
                } else if (nums[i] > monotonic_decreasing_queue.front()) {
                    while (!monotonic_decreasing_queue.empty() && monotonic_decreasing_queue.front() < nums[i]) {
                        monotonic_decreasing_queue.pop();
                    }
                    monotonic_decreasing_queue.push(nums[i]);
                }
            }


            for (int i = k; i < nums.size(); i++) {
                int left_num = nums[i - k];
                
                int k = monotonic_decreasing_queue.front();
                if (left_num == k) {
                    monotonic_decreasing_queue.pop();
                }
                answer.push_back(k);

                if (nums[i] <= monotonic_decreasing_queue.front()) {
                    monotonic_decreasing_queue.push(nums[i]);
                } else {
                    while (!monotonic_decreasing_queue.empty() && monotonic_decreasing_queue.front() < nums[i]) {
                        monotonic_decreasing_queue.pop();
                    }
                    monotonic_decreasing_queue.push(nums[i]);
                }
            }

            int queue_size = monotonic_decreasing_queue.size();
            for (int i = 0; i < queue_size; i++) {
                std::cout << monotonic_decreasing_queue.front() << std::endl;

                monotonic_decreasing_queue.push(monotonic_decreasing_queue.front());
                monotonic_decreasing_queue.pop();
            }

            return answer;
        }
};