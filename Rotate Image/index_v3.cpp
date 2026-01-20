#include <vector>
#include <string>
#include <list>
#include <queue>
#include <unordered_map>
#include <iostream>

class Solution {

    private:
        void show_matrix(std::vector<std::vector<int>>& matrix) {
            int matrix_size = matrix.size();
            for (int i = 0; i < matrix_size; i++) {
                for (int j = 0; j < matrix_size; j++) {
                    std::cout << matrix[i][j] << ", ";
                }
                std::cout << std::endl;
            }
            std::cout << "-------------" << std::endl;
        }

    public:
        void rotate(std::vector<std::vector<int>>& matrix) {
            
            int matrix_size = matrix.size();
            std::vector<int> result(matrix_size * matrix_size);
            
            for (int i = 0, k = matrix_size - 1; i < matrix_size; i++, k--) {
                for (int j = 0, l = matrix_size - 1; j < matrix_size && l >= k; j++, l--) {
                    std::swap(matrix[i][j], matrix[l][k]);
                }
                this->show_matrix(matrix);
            }

        }
};