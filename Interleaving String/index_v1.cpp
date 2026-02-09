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
    private:
        bool canInterleave(std::vector<std::vector<int>>&dp, const int s1_size, const int s2_size, int idx1, int idx2) {
            if (idx1 >= s1_size && idx2 >= s2_size) {
                return true;
            }
        }
    public:
        bool isInterleave(std::string s1, std::string s2, std::string s3) {
            int s1_size = s1.size();
            int s2_size = s2.size();
            int s3_size = s3.size();
            if (s1_size + s2_size != s3_size) {
                return false;
            }

            std::vector<std::vector<int>> dp(s1_size + 1, std::vector<int>(s2_size + 1, -1));

        }
};

