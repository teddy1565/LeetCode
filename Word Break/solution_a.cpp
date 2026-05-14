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
#include <unordered_set>

class Solution {
    private:
        bool check(std::string & s, std::unordered_set<std::string> & word_set, int start, std::vector<int> & memo) {
            if (start >= s.size()) {
                return true;
            }
            if (memo[start] != -1) {
                return memo[start];
            }
            for (int i = start + 1; i <= s.size(); i++) {
                if (word_set.count(s.substr(start, i - start)) && check(s, word_set, i, memo)) {
                    return memo[start] = 1;
                }
            }

            return memo[start] = 0;
        }
    public:
        bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
            std::unordered_set<std::string> word_set(wordDict.begin(), wordDict.end());
            std::vector<int> memo(s.size(), -1);
            
            return check(s, word_set, 0, memo);
        }
};