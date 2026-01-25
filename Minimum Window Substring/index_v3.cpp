#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>

class Solution {
    public:
        static std::string minWindow(std::string s, std::string t) {
            if (t.size() > s.size()) {
                return "";
            }

            std::vector<int> hash_map(256, 0);
            int left = 0;
            int right = 0;
            int count = 0;
            int answer_index = -1;
            int minimum_answer = INT_MAX;
            
            for (int i = 0; i < t.size(); i++) {
                // 代表我還差多少能滿足t
                hash_map[t[i]] += 1;

                // 當歸0時候，代表我還清所有債務，滿足了target的條件
                count += 1;
            }

            while (right < s.size()) {
                if (hash_map[s[right]] > 0) {
                    count -= 1;
                }

                hash_map[s[right]] -= 1;

                // 代表目前滿足了條件
                while (count == 0) {
                    // 如果目前的條件，長度也低於最小的答案
                    if (right - left + 1 < minimum_answer) {
                        minimum_answer = right - left + 1;
                        answer_index = left;
                    }

                    // 左邊界開始移動
                    hash_map[s[left]] += 1;

                    if (hash_map[s[left]] > 0) {
                        // 由於左邊界的移動，導致需要滿足的count又變大了
                        count += 1;
                    }
                    left += 1;
                }

                right += 1;
            }


            return answer_index == -1 ? "" : s.substr(answer_index, minimum_answer);

        }
};