#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>


class Solution {
    public:
        std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
            // find the first position
            // i will compare the newInterval[0] and intervals[i][1], if intervals[i][1] > newInterval[0], means range in intervals[i][0] ~ intervals[i][1] - 1;
            // and the i will compare the newInterval[1] with intervals[i][0], if intervals[i][0] > newInterval[1], means, the end number is intervals[i][1];

            std::vector<std::vector<int>> answer;

            int current_find = 0;
            int i = 0;
            std::vector<int> overlap;
            for (; i < intervals.size(); i++) {
                /**
                 * @brief 
                 * Conditional
                 * 1. intervals[i][1] >= newInterval[0]
                 * 2. intervals[i][1] < newInterval[0]
                 * 
                 * 3. intervals[i][0] 
                 * 
                 * [3, 5][6, 10]
                 * [3, 7][8, 10]
                 * [3, 8][9, 10]
                 */
                
                if (intervals[i][1] >= newInterval[0]) {
                    if (intervals[i][0] < newInterval[0]) {
                        newInterval[0] = intervals[i][0];
                    }
                    break;
                }

                answer.push_back(intervals[i]);
            }

            for(; i < intervals.size(); i++) {
                if (intervals[i][0] <= newInterval[1] && intervals[i][1] > newInterval[1]) {
                    newInterval[1] = intervals[i][1];
                    i += 1;
                    break;
                } else if (intervals[i][0] > newInterval[1] && intervals[i][1] > newInterval[1]) {
                    break;
                }
            }

            answer.push_back(newInterval);
            for (; i < intervals.size(); i++) {
                answer.push_back(intervals[i]);
            }

            return answer;

        }
};