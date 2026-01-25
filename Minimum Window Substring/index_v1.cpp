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
class Solution {
    public:
        std::string minWindow(std::string s, std::string t) {
            if (t.size() > s.size()) {
                return "";
            }
            int min_ans = INT_MAX;
            std::string answer = "";

            int source_size = s.size();
            int target_size = t.size();

            std::unordered_map<char, int> str_map;
            std::unordered_map<char, int> str_runtime_map;

            for (int i = 0; i < 26; i++) {
                str_map[i + 'a'] = 0;
                str_map[i + 'A'] = 0;
                str_runtime_map[i + 'a'] = 0;
                str_runtime_map[i + 'A'] = 0;
            }


            for (int i = 0; i < target_size; i++) {
                str_map[t[i]] += 1;
            }


            std::list<char> str_runtime_queue;

            for (int i = 0; i < source_size; i++) {
                
                str_runtime_queue.push_back(s[i]);

                if (str_map[s[i]] != 0) {
                    str_runtime_map[s[i]] += 1;
                }

                if (str_runtime_map[s[i]] > str_map[s[i]]) {
                    char k = str_runtime_queue.front();
                    if (k == s[i]) {
                        while (!str_runtime_queue.empty() && str_runtime_map[k] > str_map[k]) {
                            str_runtime_queue.pop_front();
                            if (str_map[str_runtime_queue.front()] != 0) {
                                str_runtime_map[k] -= 1;
                                k = str_runtime_queue.front();
                            }
                        }
                    }
                }

                while (!str_runtime_queue.empty() && str_map[str_runtime_queue.front()] == 0) {
                    str_runtime_queue.pop_front();
                }

                bool check_is_sames = true;
                for (int i = 0; i < 26; i++) {
                    if (str_map[i + 'a'] > 0 && str_runtime_map[i + 'a'] < str_map[i + 'a']) {
                        check_is_sames = false;
                        break;
                    }
                    if (str_map[i + 'A'] > 0 && str_runtime_map[i + 'A'] < str_map[i + 'A']) {
                        check_is_sames = false;
                        break;
                    }
                }
                if (check_is_sames == true && str_runtime_queue.size() > 0 && str_runtime_queue.size() < min_ans) {
                    min_ans = str_runtime_queue.size();
                    answer.assign(str_runtime_queue.begin(), str_runtime_queue.end());
                }
            }

            return answer;
        }
};