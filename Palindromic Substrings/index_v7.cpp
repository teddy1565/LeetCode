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
#include <array>
#include <set>
#include <numeric>

// aaad
// aaa d
// aaa

// ⌊(半徑 + 1) / 2⌋ = ⌊(0 + 1) / 2⌋ = 0。
class Solution {
    public:
        static int countSubstrings(std::string s) {
            if (s.empty()) {
                return 0;
            }


            int n = s.size();


            std::string t;
            t.append("^");
            for (int i = 0; i < n; i++) {
                t.append("#");
                t.insert(t.end(), s[i]);
            }
            t.append("#$");


            int k = t.size();
            int ans = 0;

            std::vector<int> p(k, 0);
            int R = 0;
            int C = 0;

            for (int i = 1; i < k - 1; i++) {
                if (i < R) {
                    p[i] = std::min(R - i, p[C * 2 - i]);
                } else {
                    p[i] = 0;
                }
                
                while (t[i + p[i] + 1] == t[i - p[i] - 1]) {
                    p[i] += 1;
                }

                ans += (p[i] + 1) / 2;

                if (i + p[i] > R) {
                    R = i + p[i];
                    C = i;
                }
            }
            
            return ans;
        }
};