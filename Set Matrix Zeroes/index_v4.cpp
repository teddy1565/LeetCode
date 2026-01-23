#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>

class Solution {

    private:
        void show_matrix(std::vector<std::vector<int>>& matrix) {
            for (int i = 0; i < matrix.size(); i++) {
                for (int j = 0; j < matrix[i].size(); j++) {
                    std::cout << matrix[i][j] << ", ";
                }
                std::cout << std::endl;
            }

            std::cout << "-----------------" << std::endl;
        }
    public:
        void setZeroes(std::vector<std::vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();

            // int xy[4];
            // xy[0] = matrix[0][0];
            // xy[1] = matrix[0][m-1];
            // xy[2] = matrix[n-1][0];
            // xy[3] = matrix[n-1][m-1];

            int slide[4] = {
                0,  // top
                0,  // right
                0,  // bottom
                0   // left
            };

            for (int i = 0; i < m; i++) {
                if (matrix[0][i] == 0) {
                    slide[0] = 1;
                }
                if (matrix[n - 1][i] == 0) {
                    slide[2] = 1;
                }
            }

            show_matrix(matrix);

            for (int i = 0; i < m; i++) {
                if (matrix[0][i] == 0) {
                    matrix[n - 1][i] = 0;
                }
                if (matrix[n - 1][i] == 0) {
                    matrix[0][i] = 0;
                }
            }

            show_matrix(matrix);

            for (int i = 0; i < n; i++) {
                if (matrix[i][0] == 0) {
                    slide[3] = 1;
                }
                if (matrix[i][m - 1] == 0) {
                    slide[1] = 1;
                }
            }

            show_matrix(matrix);

            for (int i = 0; i < n; i++) {
                if (matrix[i][0] == 0) {
                    matrix[i][m - 1] = 0;
                }
                if (matrix[i][m - 1] == 0) {
                    matrix[i][0] = 0;
                }
            }

            show_matrix(matrix);
            

            for (int i = 1; i < n - 1; i++) {
                for (int j = 1; j < m - 1; j++) {
                    if (matrix[i][j] == 0) {
                        matrix[i][0] = 0;
                        matrix[i][m - 1] = 0;
                        matrix[0][j] = 0;
                        matrix[n - 1][j] = 0;
                    }
                }
            }

            for (int i = 1; i < m - 1; i++) {
                if (matrix[0][i] == 0) {
                    for (int j = 0; j < n; j++) {
                        matrix[j][i] = 0;
                    }
                } else if (matrix[n - 1][i] == 0) {
                    for (int j = 0; j < n; j++) {
                        matrix[j][i] = 0;
                    }
                }
            }

            for (int i = 1; i < n - 1; i++) {
                if (matrix[i][0] == 0) {
                    for (int j = 0; j < m; j++) {
                        matrix[i][j] = 0;
                    }
                } else if (matrix[i][m - 1] == 0) {
                    for (int j = 0; j < m; j++) {
                        matrix[i][j] = 0;
                    }
                }
            }
            
            if (slide[0] != 0) {
                for (int i = 0; i < m; i++) {
                    matrix[0][i] = 0;
                }
            }

            if (slide[1] != 0) {
                for (int i = 0; i < n; i++) {
                    matrix[i][m - 1] = 0;
                }
            }

            if (slide[2] != 0) {
                for (int i = 0; i < m; i++) {
                    matrix[n - 1][i] = 0;
                }
            }

            if (slide[3] != 0) {
                for (int i = 0; i < n; i++) {
                    matrix[i][0] = 0;
                }
            }

        }
};
