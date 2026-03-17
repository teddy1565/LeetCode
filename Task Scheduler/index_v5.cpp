
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

class Solution {
    public:
        int leastInterval(std::vector<char>& tasks, int n) {
            std::unordered_map<char, int> m;
            std::priority_queue<int> q;
            int res = 0;
            int cycle = n + 1;
            int tasks_size = tasks.size();
            for (int i = 0; i < tasks_size; i++) {
                char task = tasks[i];
                if (m.find(task) == m.end()) {
                    m[task] = 0;
                }
                m[task] += 1;
            }

            for (auto pair : m) {
                q.push(pair.second);
            }

            while(!q.empty()) {
                int cnt = 0;
                std::vector<int> scheduler;
                for (int i = 0; i < cycle; i++) {
                    if (!q.empty()) {
                        scheduler.push_back(q.top());
                        q.pop();
                        cnt += 1;
                    }
                }

                for (int i = 0; i < scheduler.size(); i++) {
                    scheduler[i] -= 1;
                    if (scheduler[i] > 0) {
                        q.push(scheduler[i]);
                    }
                }

                res += q.empty() ? cnt: cycle;
            }

            return res;
        }
};