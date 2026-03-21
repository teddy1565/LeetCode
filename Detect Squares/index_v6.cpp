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

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")


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

        static int count_squares(std::unordered_map<int, std::unordered_map<int, int>> & data_points_x, std::unordered_map<int, std::unordered_map<int, int>> & data_points_y, std::vector<int> & point) {
            int max_count = 0;

            for (const auto x : (data_points_x[point[0]])) {
                for (const auto y : (data_points_y[point[1]])) {

                    if (std::abs(point[1] - x.first) != std::abs(point[0] - y.first)) continue;
                    if ((y.first == point[0] && x.first == point[1])) continue;
                    if (data_points_x.find(y.first) == data_points_x.end()) continue;
                    if (data_points_x[y.first].find(x.first) == data_points_x[y.first].end()) continue;
                    
                    max_count += (data_points_x[y.first][x.first] * data_points_x[point[0]][x.first] * data_points_x[y.first][point[1]]);
                }
            }

            return max_count;
        }

    public:
        

        DetectSquares() {
            data_points_x.reserve(1024);
            data_points_y.reserve(1024);
        }
        
        inline void add(std::vector<int> point) {
            if (data_points_x.find(point[0]) == data_points_x.end())
                data_points_x[point[0]] = std::unordered_map<int, int>();

            ++ data_points_x[point[0]][point[1]];


            
            if (data_points_y.find(point[1]) == data_points_y.end())
                data_points_y[point[1]] = std::unordered_map<int, int>();

            ++ data_points_y[point[1]][point[0]];
        }
        
        int count(std::vector<int> point) {
            
            if (data_points_x.find(point[0]) == data_points_x.end()) return 0;
            if (data_points_y.find(point[1]) == data_points_y.end()) return 0;

            return count_squares(data_points_x, data_points_y, point);
        }
};