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
            int high = row_size * col_size - 1;

            while (low < high) {
                int mid = low + (high - low) / 2;
                int m = matrix[mid / col_size][mid % col_size];
                if (m < target) {
                    low = mid + 1;
                } else if (m == target) {
                    return true;
                } else if (m > target) {
                    high = mid;
                }
            }

            if (matrix[low / col_size][low /row_size] == target) {  // check if 1
                return true;
            }

            return false;
        }
};