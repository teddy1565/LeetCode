#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>
#include <stack>

class Solution {
    public:
        long long int largest(std::vector<int>& nums) {
            int nums_size = nums.size();
            long long int largest_sum = 0;
            std::vector<int> prev_biggest_range(nums_size, 1);
            std::vector<int> next_biggest_range(nums_size, 1);
            std::stack<int> biggest_stack;

            for (int i = 0; i < nums_size; i++) {
                while (!biggest_stack.empty() && nums[biggest_stack.top()] <= nums[i]) {
                    int index = biggest_stack.top();
                    biggest_stack.pop();
                    next_biggest_range[index] = i - index;
                }
                biggest_stack.push(i);
            }
            
            while (!biggest_stack.empty()) {
                int index = biggest_stack.top();
                next_biggest_range[index] = nums_size - index;
                biggest_stack.pop();
            }

            for (int i = nums_size - 1; i >= 0; i--) {
                while (!biggest_stack.empty() && nums[biggest_stack.top()] < nums[i]) {
                    int index = biggest_stack.top();
                    biggest_stack.pop();
                    prev_biggest_range[index] = index - i;
                }
                biggest_stack.push(i);
            }

            while (!biggest_stack.empty()) {
                int index = biggest_stack.top();
                prev_biggest_range[index] = index + 1;
                biggest_stack.pop();
            }

            for (int i = 0; i < nums_size; i++) {
                largest_sum += (long long int) prev_biggest_range[i] * next_biggest_range[i] * nums[i];
            }

            return largest_sum;
        }

        long long int smallest(std::vector<int>& nums) {
            int nums_size = nums.size();
            std::vector<int> previous_small_range(nums_size, 1);
            std::vector<int> next_small_range(nums_size, 1);
            long long int smallest_sum = 0;
            std::stack<int> smallest_stack;

            // --- 先檢查由左到右
            // 找右邊邊界，代表的是對於nums[i]而言有多少次自己是最小的主角

            for (int i = 0; i < nums_size; i++) {
                // 如果stack不是空的，而且nums[stack[0]] >= nums[i] 則持續做
                while (!smallest_stack.empty() && nums[smallest_stack.top()] >= nums[i]) {
                    int index = smallest_stack.top();
                    smallest_stack.pop();
                    next_small_range[index] = i - index;
                }

                smallest_stack.push(i);
            }

            while (!smallest_stack.empty()) {
                int index = smallest_stack.top();
                next_small_range[index] = nums_size - index;
                smallest_stack.pop();
            }

            // --- 

            for (int i = nums_size - 1; i >= 0; i--) {
                while (!smallest_stack.empty() && nums[smallest_stack.top()] > nums[i]) {
                    int index = smallest_stack.top();
                    smallest_stack.pop();
                    previous_small_range[index] = index - i;
                }
                smallest_stack.push(i);
                
            }

            while (!smallest_stack.empty()) {
                int index = smallest_stack.top();
                previous_small_range[index] = index + 1;
                
                smallest_stack.pop();
            }

            for (int i = 0; i < nums_size; i++) {
                smallest_sum += (long long int) next_small_range[i] * previous_small_range[i] * nums[i];
            }

            return smallest_sum;
        }

        long long int subArrayRanges(std::vector<int>& nums) {
            return this->largest(nums) - this->smallest(nums);
        }
};