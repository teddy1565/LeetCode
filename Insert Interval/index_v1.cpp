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

            

            int intervals_size = intervals.size();
            if (intervals[intervals_size - 1][1] < newInterval[0]) {
                intervals.push_back(newInterval);
                return intervals;
            }

            std::vector<std::vector<int>> answer;

            std::vector<int> overlap;
            bool can_push_back = true;
            for (int i = 0, j = 0, k = 1; i < intervals.size(); i++) {
                /**
                 * @brief 
                 * Conditional
                 * 1. intervals[i][1] >= newInterval[0]
                 * 2. intervals[i][1] < newInterval[0]
                 * 
                 * 3. intervals[i][0] > newInterval[1]
                 * 4. intervals[i][0] == newInterval[1]
                 * 
                 * 5. intervals[i][0] < newInterval[1] && intervals[i - 1][1] < newInterval[1]
                 * 6. intervals[i][0] < newInterval[1] && intervals[i - 1][1] ==  newInterval[1]
                 */
                if (k < 3 && k == 1 && intervals[i][k] >= newInterval[j]) {
                    if (newInterval[j] >= intervals[i][j]) {
                        overlap[j] = intervals[i][j];
                        k = 0;
                        j = 1;
                        can_push_back = false;
                    } else if (newInterval[j] <= intervals[i][j]) {
                        overlap[j] = newInterval[j];
                        k = 0;
                        j = 1;
                        can_push_back = false;
                    }
                } else if (k < 3 && k == 0 && intervals[i][k] > newInterval[j]) {
                    if (newInterval[j] >= intervals[i - 1][j]) {
                        overlap[j] = newInterval[j];
                        can_push_back = true;
                        k = 3;
                    } else if (newInterval[j] < intervals[i - 1][j]) {
                        overlap[j] = intervals[i - 1][j];
                        can_push_back = true;
                        k = 3;
                    }
                } else if (k < 3 && k == 0 && intervals[i][k] == newInterval[j]) {
                    
                }

                if (can_push_back == true) {
                    answer.push_back(intervals[i]);
                }
            }
        }
};