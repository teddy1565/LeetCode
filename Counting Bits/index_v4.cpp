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
    public:
        std::vector<int> countBits(int n) {
            std::vector<int> ans(n + 1, 0);

            for (int i = 1; i <= n; i++) {
                if (i & 1) {
                    ans[i] = ans[i - 1] + 1;
                } else {
                    ans[i] = ans[i - (i >> 1)];
                    // ans[i] = ans[i - (i / 2)];
                }
            }

            return ans;
        }
};