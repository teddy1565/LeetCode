#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <stack>


class Solution {
    private:
        static int count_bit(int n) {
            int k = 0;
            for (int i = 0; i < 17; i++) {
                k += ((n >> i) & 1);
            }

            return k;
        }
    public:
        std::vector<int> countBits(int n) {
            std::vector<int> ans;

            for (int i = 0; i <= n; i++) {
                int ans_bits = count_bit(i);
                ans.push_back(ans_bits);
            }

            return ans;
        }
};