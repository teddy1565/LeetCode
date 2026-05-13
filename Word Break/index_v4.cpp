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

class Solution {
    public:
        bool wordBreak(std::string s, std::vector<std::string>& wordDict) {

            int n = s.size();
            int m = wordDict.size();
            std::vector<char *> word_dict;
            std::vector<char *> word_index;

            for (int i = 0; i < m; i++) {
                //word_count[wordDict[i]] = 1;    // string index is n - 1
                wordDict[i].insert(0, "\0");
                word_dict.push_back(&wordDict[i].back());   // maybe use this?
                word_index.push_back(&wordDict[i].back());
            }

            std::vector<bool> dp(n + 1, false);
            std::vector<bool> select_str(m, true);

            dp[n] = true;
            
            for (int i = n - 1; i >= 0; i--) {
                std::cout << s[i] << std::endl;
                for (int k = 0; k < m; k++) {
                    char *ptr = word_dict[k];
                    // std::cout << *ptr << ", " << select_str[k] << " | ";
                    if (*ptr == '\0') {
                        select_str.assign(m, true);
                        word_dict[k] = word_index[k];
                        k = 0;
                        ptr = word_dict[k];
                    }
                    if (*ptr == s[i] && select_str[k] == true) {
                        std::cout << *ptr << ", ";
                        dp[i] = dp[i + 1];
                        ptr--;
                        if ((k == m - 1) && (*ptr == '\0')) {
                            ptr = word_index[k];
                            select_str.assign(m, true);
                        }
                        word_dict[k] = ptr;
                    } else {
                        select_str[k] = false;
                    }
                }

                std::cout << std::endl;
                for (int e = 0; e < m; e++) {
                    std::cout << select_str[e] << ", ";
                }
                std::cout << std::endl;
                std::cout << std::endl;

                
            }

            for (int i = 0; i < dp.size(); i++) {
                std::cout << dp[i] << ", ";
            }
            std::cout << std::endl;

            return dp[0];
        }
};