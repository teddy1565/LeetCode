#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

class Solution {
public:
    static std::string minWindow(std::string s, std::string t) {
        if (t.size() > s.size()) return "";

        std::vector<int> hash(256, 0);
        for (char c : t) hash[c]++;

        int left = 0, right = 0;
        int min_length = 1e9;
        int source_index = -1;
        int count = 0; // 目前視窗內已滿足 t 的字元總數

        while (right < s.size()) {
            // 步驟 1: 擴張右邊界
            // 如果 hash[s[right]] > 0，表示這是一個我們需要的字元
            if (hash[s[right]] > 0) {
                count++;
            }
            hash[s[right]]--; // 進入視窗，需求減 1

            // 步驟 2: 當視窗完全包含 t 時，嘗試縮小左邊界
            while (count == t.size()) {
                if (right - left + 1 < min_length) {
                    min_length = right - left + 1;
                    source_index = left;
                }

                // 準備移出 left 指標指向的字元
                hash[s[left]]++; 
                // 如果 hash 變回正數，代表我們剛剛移走了一個「必要的」字元
                if (hash[s[left]] > 0) {
                    count--;
                }
                left++; // 無論如何，left 都要右移
            }
            right++;
        }

        return source_index == -1 ? "" : s.substr(source_index, min_length);
    }
};