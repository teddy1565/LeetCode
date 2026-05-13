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
        static bool helper(const std::string & s) {
            for (int i = 0, j = s.size() - 1; i < j; i++, j--) {
                if (s[i] != s[j]) {
                    return false;
                }
            }

            return true;
        }
    public:
        static int countSubstrings(std::string s) {
            int ans = 0;
            int str_length = s.size();
            for (int i = 1; i <= str_length; i++) {
                for (int j = 0; j < str_length; j++) {
                    if (i + j > str_length) {
                        break;
                    }
                    if (helper(s.substr(j, i)) == true) {
                        ans += 1;
                    }
                }
            }

            return ans;
        }
};