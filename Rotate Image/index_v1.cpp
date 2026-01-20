#include <vector>
#include <string>
#include <list>
#include <queue>
#include <unordered_map>

class Solution {
    public:
        void rotate(std::vector<std::vector<int>>& matrix) {
            int matrix_size = matrix.size();
            std::vector<std::vector<int>> result(matrix_size);
            for (int i = 0, k = matrix_size - 1; i < matrix_size; i++, k--) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    result[j][k] = matrix[i][j];
                }
            }
            for (int i = 0; i < matrix_size; i++) {
                for (int j = 0; j < matrix_size; j++) {
                    matrix[i][j] = result[i][j];
                }
            }
        }
};