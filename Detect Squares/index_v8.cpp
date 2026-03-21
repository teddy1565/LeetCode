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

    public:
        

        DetectSquares() {
            data_points_x.reserve(1024);
        }
        
        inline void add(std::vector<int> point) {
            if (data_points_x.find(point[0]) == data_points_x.end())
                data_points_x[point[0]] = std::unordered_map<int, int>();

            ++ data_points_x[point[0]][point[1]];
        }
        
        int count(std::vector<int> point) {
            
            if (data_points_x.find(point[0]) == data_points_x.end()) return 0;

            int cnt = 0;

            for (auto y : data_points_x[point[0]]) {
                if (y.first == point[1]) continue;

                // int p2_x = point[0];
                // int p2_y = y.first;

                int side_length = std::abs(point[1] - y.first);
                int p3_x_a = point[0] + side_length;
                int p3_x_b = point[0] - side_length;

                // 正負方向
                // int p3_y_a = data_points_x[p3_x_a][point[1]];
                // int p4_x = p3_x_a;
                // int p4_y = y.first;

                // check_point = [point[0], point[1]]
                // p2          = [point[0], y.first]
                // p3          = [point[0] + side_length, data_points_x[p3_x_a][point[1]]]
                // p4          = [p3_x, y.first]

                if (
                    data_points_x.find(p3_x_a) != data_points_x.end() && 
                    data_points_x[p3_x_a].find(point[1]) != data_points_x[p3_x_a].end() &&
                    data_points_x[p3_x_a].find(y.first) != data_points_x[p3_x_a].end()
                ) {
                    cnt += data_points_x[point[0]][y.first] * data_points_x[p3_x_a][point[1]] * data_points_x[p3_x_a][y.first];
                }

                if (
                    data_points_x.find(p3_x_b) != data_points_x.end() && 
                    data_points_x[p3_x_b].find(point[1]) != data_points_x[p3_x_b].end() &&
                    data_points_x[p3_x_b].find(y.first) != data_points_x[p3_x_b].end()
                ) {
                    cnt += data_points_x[point[0]][y.first] * data_points_x[p3_x_b][point[1]] * data_points_x[p3_x_b][y.first];
                }

                
            }

            return cnt;
        }
};