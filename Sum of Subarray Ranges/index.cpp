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
    private:

        static long long int largest(std::vector<int>& nums) {
            int nums_size = nums.size();
            std::vector<int> right_large_range(nums_size, 1);
            std::vector<int> left_large_range(nums_size, 1);
            std::stack<int> largest_stack;
            long long int sum = 0;

            for (int i = 0; i < nums_size; i++) {
                while (!largest_stack.empty() && nums[largest_stack.top()] <= nums[i]) {
                    int index = largest_stack.top();
                    largest_stack.pop();
                    right_large_range[index] = i - index;
                }
                largest_stack.push(i);
            }

            while (!largest_stack.empty()) {
                int index = largest_stack.top();
                largest_stack.pop();
                right_large_range[index] = nums_size - index;
            }

            for (int i = nums_size - 1; i >= 0; i--) {
                while (!largest_stack.empty() && nums[largest_stack.top()] < nums[i]) {
                    int index = largest_stack.top();
                    largest_stack.pop();
                    left_large_range[index] = index - i;
                }
                largest_stack.push(i);
            }

            while (!largest_stack.empty()) {
                int index = largest_stack.top();
                largest_stack.pop();
                left_large_range[index] = index - (-1);
            }

            for (int i = 0; i < nums_size; i++) {
                sum += (long long int) right_large_range[i] * left_large_range[i] * nums[i];
            }

            return sum;
        }

        static long long int smallest(std::vector<int>& nums) {
            int nums_size = nums.size();
            // Record How many time for nums[i] is smallest
            std::vector<int> right_small_range(nums_size, 1);
            std::vector<int> left_small_range(nums_size, 1);

            /**
             * @brief use stack, find a range is smallest
             * 
             */
            std::stack<int> smallest_stack;
            long long int sum = 0;

            for (int i = 0; i < nums_size; i++) {
                // if nums[i] < nums[smallest_stack.top()], means nums[smallest_stack.top()] is not smallest
                while (!smallest_stack.empty() && nums[smallest_stack.top()] >= nums[i]) {
                    int index = smallest_stack.top();
                    smallest_stack.pop();
                    right_small_range[index] = i - index;
                }
                smallest_stack.push(i);
            }

            while (!smallest_stack.empty()) {
                int index = smallest_stack.top();
                smallest_stack.pop();
                right_small_range[index] = nums_size - index;
            }

            for (int i = nums_size - 1; i >= 0; i--) {
                while (!smallest_stack.empty() && nums[smallest_stack.top()] > nums[i]) {
                    int index = smallest_stack.top();
                    smallest_stack.pop();
                    left_small_range[index] = index - i;
                }
                smallest_stack.push(i);
            }

            while (!smallest_stack.empty()) {
                int index = smallest_stack.top();
                smallest_stack.pop();
                left_small_range[index] = index - (-1); // means left to head
            }

            for (int i = 0; i < nums_size; i++) {
                sum += (long long int) nums[i] * left_small_range[i] * right_small_range[i];
            }

            return sum;
        }

    public:
        static long long int subArrayRanges(std::vector<int>&  nums) {
            // Answer = (Max(S1) - Min(S1)) + (Max(S2) - Min(S2)) + ..... + ((Max(Sn) - Min(Sn))
            // Answer = (Max(S1) + Max(S2) + ... + Max(Sn)) - (Min(S1) + Min(S2) + ... + Min(Sn))
            // S = total sub array
            // Answer = Sigma 'S' (Max(S) - Min(S))
            // Answer = Sigma (Max(S)) - Sigma (Min(S))
            //             Task A            Task B

            // Question: Contribution Technique
            // : "nums[i], how many times is bigest in all subarray?"
            // 
            // Sigma (i = 0 to n - 1) (nums[i] * k)
            //

            // if nums[i] is biggest, the subarray must
            // 1. Left margin can't > nums[i]
            // 2. Right margin can't > nums[i]
            //

            return largest(nums) - smallest(nums);
        }
};
