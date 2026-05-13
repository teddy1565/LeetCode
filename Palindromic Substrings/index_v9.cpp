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
            
            std::string T;
            T.append("^"); // padding start string
            for (int i = 0; i < s.size(); ++i) {    // ++i = incq
                T.append("#");
                T.insert(T.end(), s[i]);
            }
            T.append("#$");

            int ans = 0;
            int k = T.size();
            std::vector<int> P(k, 0);   // store index 'i' how many possible

            int R = 0;  // maximum Right range
            int C = 0;  // r

            for (int i = 1; i < k - 1; ++i) {   // string limit char '^' and '$'
                if (i < R) {
                    P[i] = std::min(R - i, P[C * 2 - i]); // check safe range, and extends old P[i]
                } else {
                    P[i] = 0;   // from 0 start, that means T[i + 0 + 1] == T[i - 0 - i] ...... T[i + n + 1] == T[i - n - 1]
                }

                while (T[i + P[i] + 1] == T[i - P[i] - 1]) {
                    ++P[i];
                }

                ans += (P[i] + 1) / 2;

                if (i + P[i] > R) { // if range over then R, update R and C
                    R = i + P[i];
                    C = i;
                }
            }

            return ans;
        }
};