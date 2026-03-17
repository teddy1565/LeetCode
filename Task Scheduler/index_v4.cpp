
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
            int res = 0;
            int cycle = n + 1;
            std::unordered_map<char, int> m;
            std::priority_queue<int> q;
            for (char c : tasks) {
                if (m.find(c) == m.end()) {
                    m[c] = 0;
                }
                m[c] += 1;
            }

            for (auto a : m) {
                // k, v
                q.push(a.second);
            }

            while (!q.empty()) {
                int cnt = 0;
                std::vector<int> t;
                for (int i = 0; i < cycle; i++) {
                    if (!q.empty()) {
                        t.push_back(q.top());
                        q.pop();
                        cnt += 1;
                    }
                }

                for (int i = 0; i < t.size(); i++) {
                    t[i] -= 1;
                    if (t[i] > 0) {
                        q.push(t[i]);
                    }
                }

                res += q.empty() ? cnt : cycle;
            }

            return res;
        }
};