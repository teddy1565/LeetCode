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

// acdcb | a*c?b
// abcde | *a*b*c*d*e*
// abefcdgiescdf | ab*cd?i*f
class Solution {
    public:
        bool isMatch(std::string s, std::string p) {
            int p_size = p.size();
            int s_size = s.size();
            
            std::vector<std::vector<bool>> dp(p_size, std::vector<bool>(s_size, false));

            for (int i = p_size - 1; i >= 0; i--) {
                
                for (int j = s_size - 1; j >= 0; j--) {
                    
                }
            }
        }
};