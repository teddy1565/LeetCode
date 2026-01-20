#include <iostream>
#include <vector>
#include <list>
#include <unordered_map>
#include <algorithm>

class Solution {
    private:
    public:
        double myPow(double x, int n) {
            if (n == 0) {
                return 1;
            } else if (x == 0 || x == 1 || n == 1) {
                return x;
            } else if (n == -1) {
                return 1 / x;
            }
            int ans = x;
            if (n < 0) {
                x = 1 / x;
            }
            if (n == INT_MIN) {
                ans = ans * x;
                n += 1;
            }
            int m = n < 0 ? -n : n;
            for (int i = 0; i < m; i++) {
                ans = ans * x;
            }

            return ans;
            
        }
};