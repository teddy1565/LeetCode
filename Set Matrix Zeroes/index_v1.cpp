#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>

class Solution {

    private: 
        void set_zero(bool & result, const int & matrix_size, std::vector<std::vector<int>>& matrix, int x, int y) {

            if (x < 0 || x >= matrix_size || y < 0 || y >= matrix_size) {
                return;
            }
            
            int original_m = 0;
            std::swap(original_m, matrix[x][y]);

            if (original_m == 0) {
                result = true;
            }

            set_zero(result, matrix_size, matrix, x, y + 1);
            // set_zero(result, matrix_size, matrix, x, y - 1);
            set_zero(result, matrix_size, matrix, x + 1, y);
            // set_zero(result, matrix_size, matrix, x - 1, y);

            if (result != true) {
                std::swap(original_m, matrix[x][y]);
            }

            return ;
        }
    public:
        void setZeroes(std::vector<std::vector<int>>& matrix) {
            int n = matrix.size();
            int m = n;
            for (int i = 0; i < n; i++) {
                bool result = false;
                this->set_zero(result, n, matrix, i, i);
            }
        }
};

int main(void) {
    auto a = new Solution();
    std::vector<std::vector<int>> matrix(3);
    matrix[0][0] = 1;
    matrix[0][1] = 1;
    matrix[0][2] = 1;

    matrix[1][0] = 1;
    matrix[1][1] = 0;
    matrix[1][2] = 1;

    matrix[2][0] = 1;
    matrix[2][1] = 1;
    matrix[2][2] = 1;

    a->setZeroes(matrix);

    for (int i = 0; i < matrix.size(); i++) {
        for (int j = 0; j < matrix.size(); j++) {
            std::cout << matrix[i][j] << ", ";
        
        }
        std::cout << std::endl;
    }
    return 0;
}