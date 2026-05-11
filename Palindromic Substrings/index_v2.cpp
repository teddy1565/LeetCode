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
class Solution {
    private:
        static void helper(std::string & s, int i, int j, int & ans) {
            while (i >= 0 && j < s.size() && s[i] == s[j]) {
                i--;
                j++;
                ans++;
            }
        }
    public:
        static int countSubstrings(std::string s) {
            if (s.empty()) {
                return 0;
            }
            int n = s.size();
            int ans = 0;
            for (int i = 0; i < n; i++) {
                helper(s, i, i, ans);
                helper(s, i, i + 1, ans);
            }
            return ans;
        }
};