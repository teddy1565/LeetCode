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
            
            int max_area = 0;
            heights.push_back(0);
            int nums_size = heights.size();

            for (int i = 0; i < nums_size; i++) {
                while (!area_stack.empty() && heights[area_stack.top()] >= heights[i]) {
                    int index = area_stack.top();
                    area_stack.pop();

                    int area = heights[index] * (area_stack.empty() ? i : (i - area_stack.top() - 1));
                    max_area = max_area > area ? max_area : area;
                
                }
                area_stack.push(i);
            }

            return max_area;
        }
};