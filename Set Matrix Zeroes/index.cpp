#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <unordered_map>

class Solution {

    private:
    public:
        void setZeroes(std::vector<std::vector<int>>& matrix) {
            int n = matrix.size();
            int m = matrix[0].size();

            std::vector<int> row_list;
            std::vector<int> col_list;

            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    if (matrix[i][j] == 0) {
                        row_list.push_back(i);
                        col_list.push_back(j);
                    }
                }
            }

            for (int i = 0; i < row_list.size(); i++) {
                int row = row_list[i];
                for (int j = 0; j < m; j++) {
                    matrix[row][j] = 0;
                }
            }

            for (int i = 0; i < col_list.size(); i++) {
                int col = col_list[i];
                for (int j = 0; j < n; j++) {
                    matrix[j][col] = 0;
                }
            }
        }
};
