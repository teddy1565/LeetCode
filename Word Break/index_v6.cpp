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
    public:
        bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
            std::unordered_set<std::string> word_set(wordDict.begin(), wordDict.end());
            std::vector<bool> dp(s.size() + 1, false);
            dp[0] = true;
            
        }
};