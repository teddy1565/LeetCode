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
            std::vector<bool> visited(s.size());
            std::queue<int> q({0});
            while(!q.empty()) {
                int start = q.front();
                q.pop();
                if (!visited[start]) {
                    for (int i = start + 1; i <= s.size(); i++) {
                        if (word_set.count(s.substr(start, i - start))) {
                            q.push(i);
                            if (i == s.size()) {
                                return true;
                            }
                        }
                        visited[start] = true;
                    }
                }
            }
            
            return false;
        }
};