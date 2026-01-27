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
            std::unordered_map<int, int> hash_map;
            int maximum = INT_MIN;
            int count = 0;
            int right = 0;
            int left = 0;
            int loop_count = 0;
            int nums_size = nums.size();

            while (right < nums_size) {
                if (hash_map.find(nums[right]) == hash_map.end()) {
                    hash_map[nums[right]] = 0;
                }
                hash_map[nums[right]] += 1;

                count += 1;
                if (nums[right] > maximum) {
                    maximum = nums[right];
                }
                
                if (count == k) {
                    answer.push_back(maximum);
                    hash_map[nums[left]] -= 1;
                    count -= 1;
                    loop_count += 1;
                    
                    // if ((left + 1) < nums_size && hash_map[maximum] == 0) {
                    //     maximum = nums[left + 1];
                    // } else 
                    if (left > 0 && hash_map[nums[left]] == 0) {
                        if (nums[left] > answer[loop_count - 1]) {
                            answer[loop_count - 1] = nums[left];
                        }
                    }
                    left += 1;
                    
                }

                right += 1;
            }

            return answer;
        }
};