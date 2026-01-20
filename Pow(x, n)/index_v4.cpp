#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

class Solution {
    private:
        const double small_float_x = 0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
        const double small_float_y = 0.00000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000001;
    public:
        double myPow(double x, int n) {
            if (n == 0) {
                return 1;
            } else if (n == 1) {
                return x;
            } else if (n == -1) {
                return 1 / x;
            } else if (x < small_float_x && x >= small_float_y) {
                return 0;
            } else if ((x * x) > 10000 || (x * x) < -10000) {
                return 0;
            } else if (n == INT_MIN) {
                int n = n / 2;
                return this->myPow(1 / x, -n) * this->myPow(1 / x, -n);
            } else if (n < 0) {
                return this->myPow(1 / x, -n);
            }

            if (n & 1) {
                n /= 2;
                return x * this->myPow(x * x, n);
            } else {
                n /= 2;
                return this->myPow(x * x, n);
            }
            
        }
};