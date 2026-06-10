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
#include <set>
#include <numeric>
#include <unordered_set>
#include <charconv>

class Solution {
    private:
        int get_distance(int x1, int y1, int x2, int y2) {
            return std::abs(x1 - x2) + std::abs(y1 - y2);
        }
    public:
        int minCostConnectPoints(std::vector<std::vector<int>>& points) {
            int points_size = points.size();
            int ans = 0;
            std::unordered_map<int, int> m;
            for (int i = 0; i < points_size; i++) {
                m[i] = -1;
            }

            for (int i = 0; i < points_size; i++) {
                int biggest = INT_MAX;
                int minimum_index = -1;
                for (int j = 0; j < points_size; j++) {
                    if (i == j || m[i] == j) {
                        continue;
                    }

                    int distance = get_distance(points[i][0], points[i][1], points[j][0], points[j][1]);
                    if (distance < biggest) {
                        minimum_index = j;
                        biggest = distance;
                    }
                }
                std::cout << minimum_index << ", " << i << std::endl;
                m[minimum_index] = i;
            }

            // for (const auto & [k, v] : m) {
            //     std::cout << k << ", " << v << std::endl;
            // }
            
            for (const auto & [k, v] : m) {
                if (v == -1) continue;

                int c = get_distance(points[k][0], points[k][1], points[v][0], points[v][1]);
                std::cout << "[ " << points[k][0] << ", " << points[k][1] << " ]";
                std::cout << " => ";
                std::cout << "[ " << points[v][0] << ", " << points[v][1] << " ]";
                std::cout << " : " << c << std::endl;
                ans += c;
            }

            return ans;
        }
};