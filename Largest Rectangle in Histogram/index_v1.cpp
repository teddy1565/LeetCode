#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>

class Solution {
    public:
        int largestRectangleArea(std::vector<int>& heights) {
            std::stack<int> area_stack;
            int nums_size = heights.size();
            int max_area = 0;

            for (int i = 0; i < nums_size; i++) {
                if (!area_stack.empty() && heights[area_stack.top()] < heights[i]) {
                    int current_size = heights[area_stack.top()] * (area_stack.size() + 1);
                    if (current_size <= heights[i]) {
                        std::stack<int> empty;
                        std::swap(area_stack, empty);
                    } else {
                        int k = i;
                        std::swap(area_stack.top(), k);
                        area_stack.push(k);
                        int current_stack_max_area_size = heights[area_stack.top()] * area_stack.size();
                        max_area = max_area > current_stack_max_area_size ? max_area : current_stack_max_area_size;
                        continue;
                    }
                }

                area_stack.push(i);
                int current_stack_max_area_size = heights[area_stack.top()] * area_stack.size();
                max_area = max_area > current_stack_max_area_size ? max_area : current_stack_max_area_size;
            }

            int current_stack_max_area_size = heights[area_stack.top()] * area_stack.size();
            max_area = max_area > current_stack_max_area_size ? max_area : current_stack_max_area_size;


            return max_area;
        }
};