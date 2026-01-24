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
            // in memory is use a consequent arry to map a marix
            // so we can also reverse map make matrix like a single array

            int n = matrix.size();
            int m = matrix[0].size();

            int low = 0;
            int high = n * m - 1;

            while (low < high) {
                int mid = low + (high - low) / 2;

                if (matrix[mid / m][mid % m] < target) {
                    low = mid + 1;
                } else if (matrix[mid / m][mid % m] == target) {
                    return true;
                } else {
                    high = mid;
                }
            }

            if (matrix[low / m][low % m] == target) {
                return true;
            }

            return false;

        }
};