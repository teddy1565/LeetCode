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

            /**
             * @brief 存放查找x軸出現的y軸長度結果
             * 
             */
            std::unordered_map<int, std::vector<int>> x_axis_length;
            
            /**
             * @brief 存放查找同個y軸上出現的x軸長度結果
             * 
             */
            std::unordered_map<int, std::vector<int>> y_axis_length;

            for (auto x : (data_points_x[point[0]])) {
                int k = std::abs(point[1] - x.first);
                if (k == 0) {
                    continue;
                }
                if (x_axis_length.find(k) == x_axis_length.end()) {
                    x_axis_length[k] = std::vector<int>();
                }
                x_axis_length[k].push_back(x.first);
            }

            for (auto y : (data_points_y[point[1]])) {
                int k = std::abs(point[0] - y.first);
                if (k == 0) {
                    continue;
                }
                if (y_axis_length.find(k) == y_axis_length.end()) {
                    y_axis_length[k] = std::vector<int>();
                }
                y_axis_length[k].push_back(y.first);
            }

            std::vector<std::vector<int>> search_list;

            for (auto x : x_axis_length) {
                if (y_axis_length.find(x.first) != y_axis_length.end()) {
                    for (auto m : y_axis_length[x.first]) {
                        for (auto q : x.second) {
                            std::vector<int> s;
                            s.push_back(m);
                            s.push_back(q);
                            search_list.push_back(s);
                        }
                    }
                }
            }

            int max_count = 0;

            for (auto item : search_list) {
                if (
                    (data_points_x.find(item[0]) != data_points_x.end()) && 
                    (data_points_x[item[0]].find(item[1]) != data_points_x[item[0]].end())
                ) {
                    max_count += (data_points_x[item[0]][item[1]] * data_points_x[point[0]][item[1]] * data_points_x[item[0]][point[1]]);
                }
                
            }

            return max_count;
        }
};
