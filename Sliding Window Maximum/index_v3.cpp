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
            std::unordered_map<int, int> hash_map;
            int maximum = INT_MIN;
            int count = 0;
            int right = 0;
            int left = 0;
            int nums_size = nums.size();

            for (int i = 0; i < nums_size; i++) {
                if (hash_map.find(nums[i]) == hash_map.end()) {
                    hash_map[nums[i]] = 0;
                }
            }

            for (int i = 0; i < k; i++) {
                hash_map[nums[i]] += 1;
                if (nums[i] > maximum) {
                    maximum = nums[i];
                }
            }
            num_queue.push(maximum);
            answer.push_back(maximum);

            for (int i = k; i < nums_size; i++) {

                hash_map[nums[i - k]] -= 1;
                hash_map[nums[i]] += 1;
                

                if (num_queue.size() > k) {
                    num_queue.pop();
                }

                if (nums[i] < maximum) {
                    num_queue.push(maximum);
                } else {
                    num_queue.push(nums[i]);
                }

                // for (int j = 0; j < k; j++) {
                //     std::cout << num_queue.front() << ", ";
                //     num_queue.push(num_queue.front());
                //     num_queue.pop();
                // }

                // std::cout << std::endl;
                
            }

            

            return answer;
        }
};