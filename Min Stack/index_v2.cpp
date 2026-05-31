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
        std::stack<int> stack;
        std::stack<int> min_stack;

    public:
        MinStack() {
        }
        
        void push(int val) {
            stack.push(val);
            if (min_stack.empty() || min_stack.top() >= val) min_stack.push(val);
        }
        
        void pop() {
            if (!stack.empty() && !min_stack.empty() && stack.top() == min_stack.top()) {
                min_stack.pop();
            }
            
            if (!stack.empty()) {
                stack.pop();
            }
        }
        
        int top() {
            if (stack.empty()) {
                return -1;
            }
            return stack.top();
        }
        
        int getMin() {
            if (min_stack.empty()) {
                return -1;
            }
            return min_stack.top();
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