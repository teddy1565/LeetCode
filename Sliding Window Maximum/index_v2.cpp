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
            std::queue<int> num_queue;
            int maximum = INT_MIN;
            int count = 0;
            int right = 0;
            int left = 0;
            int nums_size = nums.size();
            num_queue.push(nums[0]);

            while (right < nums_size) {

                

                if (num_queue.empty()) {
                    num_queue.push(nums[right]);
                } else if (nums[right] > num_queue.front()) {
                    num_queue.pop();
                    num_queue.push(nums[right]);
                }

                count += 1;
                

                if (count == k) {
                    int n = num_queue.front();
                    answer.push_back(n);
                    num_queue.pop();
                    if (right + 1 < nums_size) {
                        if (nums[right + 1] <= n) {
                            num_queue.push(n);
                        } else if (nums[right + 1] > n && right - left) {
                            num_queue.push(nums[right + 1]);
                        }
                    }

                    left += 1;
                    count -= 1;
                }

                right += 1;
            }
            

            return answer;
        }
};