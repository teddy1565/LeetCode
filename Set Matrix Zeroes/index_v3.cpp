#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>
#include <array>

class Solution {

    private:
    public:
        void setZeroes(std::vector<std::vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();


            std::queue<std::array<int, 2>> zero_queue;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] == 0) {
                        std::array<int, 2> position = { i, j };
                        zero_queue.push(position);
                    }
                }
            }

            while (zero_queue.size() > 0) {
                std::array<int, 2> coordinate = zero_queue.front();
                zero_queue.pop();
                for (int i = 0; i < m; i++) {
                    matrix[coordinate[0]][i] = 0;
                }
                for (int i = 0; i < n; i++) {
                    matrix[i][coordinate[1]] = 0;
                }
            }
        }
};
