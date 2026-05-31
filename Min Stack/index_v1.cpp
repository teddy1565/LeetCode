#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>
#include <array>
#include <set>
#include <numeric>
#include <unordered_set>
#include <charconv>

// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums of unique elements, return the minimum element of this array.

// You must write an algorithm that runs in O(log n) time.
class MinStack {
    private:

        void insert(std::deque<int> & queue, int val) {
            int queue_size = queue.size();
            if (queue_size == 0) {
                queue.push_back(val);
                return;
            } else if (queue_size == 1) {
                if (val >= queue[0]) {
                    queue.push_back(val);
                } else {
                    queue.push_front(val);
                }
                return;
            }
            
            int left = 0;
            int right = queue_size - 1;
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (queue[mid] > val) {
                    right = mid;
                } else if (queue[mid] < val) {
                    left = mid + 1;
                } else if (queue[mid] == val) {
                    right = mid;
                    break;
                }
            }

            queue.insert(queue.begin() + right, val);
        }

        void remove(std::deque<int> & queue, int val) {
            int queue_size = queue.size();
            if (queue_size <= 5) {
                for (int i = 0; i < queue_size; i++) {
                    if (queue[i] == val) {
                        queue.erase(queue.begin() + i);
                        return;
                    }
                }
            }

            int left = 0;
            int right = queue_size - 1;

            while (left < right) {
                int mid = left + (right - left) / 2;
                if (queue[mid] > val) {
                    right = mid;
                } else if (queue[mid] < val) {
                    left = mid + 1;
                } else {
                    left = mid;
                    break;
                }
            }

            if (queue[left] != val) {
                return;
            }

            queue.erase(queue.begin() + left);
            return;
        }

        std::vector<int> stack_list;
        std::deque<int> queue;

    public:
        MinStack() {
        }
        
        void push(int val) {
            this->stack_list.push_back(val);
            insert(queue, val);
        }
        
        void pop() {
            int n = this->stack_list.back();
            this->stack_list.pop_back();
            remove(queue, n);
        }
        
        int top() {
            return this->stack_list.back();
        }
        
        int getMin() {
            return this->queue.front();
        }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */