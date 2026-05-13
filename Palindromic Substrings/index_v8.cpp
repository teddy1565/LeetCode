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

            std::string T;
            T.append("^");
            for (int i = 0; i < n; i++) {
                T.append("#");
                T.insert(T.end(), s[i]);
            }
            T.append("#$");

            int k = T.size();
            int ans = 0;
            std::vector<int> P(k, 0);

            int R = 0;
            int C = 0;

            for (int i = 1; i < k - 1; ++i) {
                if (i > R) {
                    // Manacher 演算法的對稱性優勢，避免從 0 開始重複比對。
                    // 背景參數已確立：你目前站在位置 i，並且完全位於一個以 C 為中心、已知最右邊界為 R 的大回文內部（前提條件為 i < R）。
                    // 在目前已知的安全範圍內，我可以直接抄對稱點的答案；但如果答案超出了安全範圍，我只能抄到邊界為止，剩下的我要自己去檢查
                    P[i] = std::min(R - i, P[C * 2 - i]);
                } else {
                    P[i] = 0;
                }

                while (T[i + P[i] + 1] == T[i - P[i] - 1]) {
                    P[i] += 1;
                }

                ans += (P[i] + 1) / 2;
                
                if (i + P[i] > R) {
                    R = i + P[i];
                    C = i;
                }
            }

            return ans;
        }
};