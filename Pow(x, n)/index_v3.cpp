#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

class Solution {
    private:
        double recurtion(double base, double x, int n) {

            int m = n < 0 ? -n : n;

            if (n > 100) {
                int nx = n / 2;
                return this->recurtion(base, x, nx + (nx & 1)) * this->recurtion(base, x, nx - (nx & 1));
            }

            
            
            // std::cout << base << " | " << x << " | " << n << std::endl;

            for (int i = 1; i < m; i++) {
                x = x * base;
            }

            if (n < 0) {
                return 1 / x;
            }
            return x;
        }
    public:
        double myPow(double x, int n) {
            if (n == 0) {
                return 1;
            } else if (x == 0 || x == 1 || n == 1) {
                return x;
            } else if (n == -1) {
                return 1 / x;
            }

            double current_value = x;

            if (n == INT_MIN) {
                current_value = x * x;
                n += 1;
            }
            return this->recurtion(x, current_value, n);
            
        }
};