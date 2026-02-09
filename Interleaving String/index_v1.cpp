#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>
#include <deque>
#include <stack>

// 需要注意DP，單純使用greedy有些可能性match不到
class Solution {
    public:
        bool isInterleave(std::string s1, std::string s2, std::string s3) {
            int s1_size = s1.size();
            int s2_size = s2.size();
            int s3_size = s3.size();
            if (s1_size + s2_size != s3_size) {
                return false;
            }

            std::vector<std::vector<int>> dp(s3_size, std::vector<int>(2, -1));


            for (int i = 1; i < s3_size; i++) {
                
            }
        }
};

