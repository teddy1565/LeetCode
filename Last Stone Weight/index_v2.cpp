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

class Solution {
    public:
        int lastStoneWeight(std::vector<int>& stones) {
            std::priority_queue<int> heap;
            int stones_size = stones.size();
            for (int i = 0; i < stones.size(); i++) {
                heap.push(stones[i]);
            }

            while(heap.size() > 1) {
                int pick = heap.top();
                heap.pop();
                int n = heap.top();
                heap.pop();
                int k = std::abs(pick - n);
                if (k != 0) {
                    heap.push(k);
                }
            }
            
            if (heap.size() == 1) {
                return heap.top();
            } else {
                return 0;
            }

        }
};