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


/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */
class DetectSquares {
    private:

        std::unordered_map<int, std::unordered_map<int, int>> data_points_x;
        std::unordered_map<int, std::unordered_map<int, int>> data_points_y;
        
    public:
        DetectSquares() {
        }
        
        void add(std::vector<int> point) {
            if (data_points_x.find(point[0]) == data_points_x.end()) {
                data_points_x[point[0]] = std::unordered_map<int, int>();
            }
            if (data_points_x[point[0]].find(point[1]) == data_points_x[point[0]].end()) {
                data_points_x[point[0]][point[1]] = 0;
            }
            data_points_x[point[0]][point[1]] += 1;


            if (data_points_y.find(point[1]) == data_points_y.end()) {
                data_points_y[point[1]] = std::unordered_map<int, int>();
            }
            if (data_points_y[point[1]].find(point[0]) == data_points_y[point[1]].end()) {
                data_points_y[point[1]][point[0]] = 0;
            }
            data_points_y[point[1]][point[0]] += 1;
        }
        
        int count(std::vector<int> point) {

            // find in same x Axis
            if (data_points_x.find(point[0]) == data_points_x.end()) {
                return 0;
            }

            // find in same y Axis
            if (data_points_y.find(point[1]) == data_points_y.end()) {
                return 0;
            }

            int max_count = 0;
            for (auto x : (data_points_x[point[0]])) {
                for (auto y : (data_points_y[point[1]])) {
                    int x_length = std::abs(point[1] - x.first);
                    int y_length = std::abs(point[0] - y.first);
                    if (x_length != y_length || (y.first == point[0] && x.first == point[1])) {
                        continue;
                    } else if (
                        (data_points_x.find(y.first) != data_points_x.end()) && 
                        (data_points_x[y.first].find(x.first) != data_points_x[x.first].end())
                    ) {
                        max_count += data_points_x[y.first][x.first] * data_points_x[point[0]][x.first] * data_points_x[y.first][point[1]];
                    }
                }
            }

            return max_count;
        }
};
