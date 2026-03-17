
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
// : tasks = ["A","A","A", "B","B","B"], n = 3
class Solution {
    public:
        static int leastInterval(std::vector<char>& tasks, int n) {
            int tasks_size = tasks.size();
            int frequency[26] = { 0 };
            int cnt = 0;

            for (int i = 0; i < tasks_size; i++) {
                
                // statistics tasks frequency
                frequency[tasks[i] - 'A'] += 1;

                // cnt is the max task frequency
                cnt = std::max(cnt, frequency[tasks[i] - 'A']);
            }

            // 假設冷卻時間為 n，則兩個相同任務之間必須間隔 n 個單位時間
            // 我們先安排出現次數最多的任務 A
            // 在 cnt 個 A 之間，會產生 cnt - 1 個「冷卻區間」
            // 每個區間的大小必須至少為 n + 1（包含一個 A 本身與 n 個間隔）。
            int ans = (cnt - 1) * (n + 1);
            // cnt * n + cnt - n - 1

            for (int i = 0; i < 26; i++) {

                // 如果有其他任務的頻次也等於最大頻次 cnt，那麼在最後一組 A 之後，這些任務還需要額外佔用一個單位的時間。
                // if task frequency equal cnt, should +1.
                // because idle
                if (frequency[i] == cnt) {
                    ans += 1;
                }
            }

            // 如果任務種類很多，足以填滿所有冷卻區間，則不需要任何空閒（Idle），總時間就是任務總數 tasks_size
            // 如果任務種類較少，無法填滿區間，則總時間會受限於冷卻時間，結果為計算出的 ans
            return std::max(ans, tasks_size);
        }
};