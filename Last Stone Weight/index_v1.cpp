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
            int stones_size = stones.size();
            if (stones_size == 1) {
                return stones[0];
            }
            
            std::sort(stones.begin(), stones.end());
            int answer = stones.back();
            stones.pop_back();
            
            while (stones.size() > 0) {
                std::sort(stones.begin(), stones.end());

                int x = stones.back();
                stones.pop_back();
                answer = std::abs(answer - x);
                if (answer == 0 && stones.size() > 0) {
                    answer = stones.back();
                    stones.pop_back();
                } else if (stones.size() > 0 && answer < stones.back()) {
                    std::swap(answer, stones.back());
                }
            }

            return answer;
        }
};