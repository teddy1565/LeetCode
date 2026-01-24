#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <unordered_map>
#include <map>
#include <algorithm>
#include <queue>

// s = "ADAADBECODEBANC" t = "ABC", O = "BANC"
// s = "ADOBECODEBANC", t = "ABC", O = "BANC"
// I thin i may can set a window from 0 to n
// when we get A, push A to queue, then record to hash map
// until our record done, record the smallest string
// then we still going to next char
// if we touch a char in target, but that char not queue first char, still going
// until tough the a char in target and is queue first char

// 需要先問的問題
// 1. target會不會大於source
// 2. 字元集是否屬於ascii
// 3. 字元集是否只有大小寫英文字母
// 4. 字串的長度限制
// 5. 
class Solution {
    public:
        static std::string minWindow(std::string s, std::string t) {
            if (t.size() > s.size()) {
                return "";
            }

            int left = 0;
            int right = 0;

            long long int min_length = 1e9;

            int source_index = -1;
            int current_target_size = 0;
            
            int source_size = s.size();
            int target_size = t.size();
            std::vector<int> hash(256, 0);

            for (int i = 0; i < target_size; i++) {
                hash[t[i]] += 1;
            }

            while (right < source_size) {

                // 如果s[right]是處於target中的一員，則current_target_size += 1
                if (hash[s[right]] > 0) {
                    current_target_size += 1;
                }

                hash[s[right]] -= 1;

                // 如果current_target_size代表的長度，等同於target的長度，則進行迴圈
                while (current_target_size == target_size) {

                    // 如果檢測到的right邊界減去left邊界(也就是上一段沒有變動的區間的left邊界)
                    // (+1 是因為right與left重疊時，仍有一個char)
                    if (right - left + 1 < min_length) {
                        min_length = right - left + 1;
                        source_index = left;
                    }

                    // 從前一個range的left邊界開始移動
                    hash[s[left]] += 1;

                    // 當邊界移動時，現有的長度統計-1 (slide window)
                    // 如果hash變回正數
                    if (hash[s[left]] > 0) {
                        current_target_size -= 1;
                    }
                    
                    // 無論如何，left都要右移
                    left += 1;
                }

                // 定位下一個區間的左邊界
                right += 1;
            }

            
            
            return source_index == -1 ? "" : s.substr(source_index, min_length);
        }
};