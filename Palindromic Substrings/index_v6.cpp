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

            for (int i = 0; i < k; i++) {
                int j = 1;
                int count = 0;
                if (i < R) {
                    int mirror = C * 2 - i;
                    j = std::min(R-i, p[mirror]);
                }
                while ((i + j < k) && (i - j >= 0) && t[i + j] == t[i - j]) {
                    count += 1;
                    j += 1;
                }
                p[i] = count;
                ans += (count + 1) / 2;
                int nextR = i + p[i];
                if (nextR > R) {
                    R = nextR;
                    C = i;
                }
            }

            for (int i = 0; i < p.size(); i++) {
                std::cout << p[i] << ", ";
            }
            std::cout << std::endl;
            
            return ans;
        }
};