
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
        static int leastInterval(std::vector<char>& tasks, int n) {
            int res = 0;
            int cycle = n + 1;
            int tasks_size = tasks.size();
            std::unordered_map<char, int> m;
            std::priority_queue<int> q;
            
            // record each task need run how much task
            for (int i = 0; i < tasks_size; i++) {
                if (m.find(tasks[i]) == m.end()) {
                    m[tasks[i]] = 0;
                }

                m[tasks[i]] += 1;
            }

            // use priority_queue record task execute times
            for (auto pair : m) {
                q.push(pair.second);
            }


            // simulate every loop for each task, and sum all counts.
            while (!q.empty()) {
                std::vector<int> scheduler;
                int cnt = 0;
                
                // run cycle, scheduler push back priority_queue top, means the max tasks need execute
                for (int i = 0; i < cycle; i++) {
                    if (!q.empty()) {
                        scheduler.push_back(q.top());
                        q.pop();
                        cnt += 1;
                    }
                }

                // loop scheduler, and Decreasing task count, and push priority_queue
                for (int i = 0; i < scheduler.size(); i++) {
                    scheduler[i] -= 1;
                    if (scheduler[i] > 0) {
                        q.push(scheduler[i]);
                    }
                }

                // return sum all count, if q is empty, add cycle count.
                res += q.empty() ? cnt : cycle;
            }

            return res;
        }
};