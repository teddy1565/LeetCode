#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        int n = s.size();
        int m = wordDict.size();

        std::vector<char*> word_dict;
        std::vector<char*> word_index;
        std::vector<int> word_size;

        for (int i = 0; i < m; i++) {
            word_size.push_back(wordDict[i].size());

            // 真的在 word 前面插入 '\0'，當作往前比對時的邊界
            wordDict[i].insert(wordDict[i].begin(), '\0');

            // 指向這個 word 的最後一個字元
            word_index.push_back(&wordDict[i].back());
            word_dict.push_back(&wordDict[i].back());
        }

        std::vector<bool> dp(n + 1, false);
        dp[n] = true;

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 0; k < m; k++) {
                int len = word_size[k];

                // 避免 dp[i + len] 越界，也避免 word 比剩下的 s 還長
                if (i + len > n) {
                    continue;
                }

                // 每次都從 word 尾巴開始比
                char* ptr = word_index[k];

                int j = i + len - 1;

                // 從右往左比：
                // s[i ... i + len - 1]
                // wordDict[k][1 ... len]
                while (j >= i && *ptr == s[j]) {
                    ptr--;
                    j--;
                }

                // 如果 ptr 走到 '\0'，代表整個 word 都匹配成功
                if (*ptr == '\0') {
                    if (dp[i + len]) {
                        dp[i] = true;
                        break;
                    }
                }

                // 保留你的 word_dict 狀態概念：
                // 這裡把目前 ptr 存回去，不過這版邏輯其實不依賴它跨輪使用
                word_dict[k] = ptr;
            }
        }

        return dp[0];
    }
};