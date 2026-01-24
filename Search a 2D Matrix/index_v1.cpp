#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>

class Solution {
    public:
        bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
            int row_size = matrix.size();
            int col_size = matrix[0].size();

            int low = 0;
            int high = matrix.size() - 1;
            
            while (low < high) {
                int mid = low + (high - low) / 2;
                if (matrix[mid][col_size - 1] < target) {
                    low = mid + 1;
                } else if (matrix[mid][col_size - 1] == target) {
                    return true;
                } else {
                    high = mid;
                }
            }

            int row_index = low;

            if (matrix[row_index][col_size - 1] < target) {
                return false;
            }

            low = 0;
            high = col_size - 1;

            while (low < high) {
                int mid = low + (high - low) / 2;
                if (matrix[row_index][mid] > target) {
                    high = mid;
                } else if (matrix[row_index][mid] == target) {
                    return true;
                } else {
                    low = mid + 1;
                }
            }

            if (matrix[row_index][low] == target) {
                return true;
            }

            return false;
        }
};