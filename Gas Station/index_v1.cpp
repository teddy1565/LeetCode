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
        int canCompleteCircuit(std::vector<int>& gas, std::vector<int>& cost) {
            int gas_size = gas.size();
            for (int i = 0; i < gas_size; i++) {
                if (gas[i] >= cost[i]) {
                    if (i > 0 && i < (gas_size - 1)) {
                        int x = gas[i] - gas[i + 1] + gas[i] - gas[i - 1];
                        int y = cost[i] - cost[i + 1] + cost[i] - cost[i - 1];
                        if (x && y) {
                            continue;
                        }
                        
                    }
                    int s = 0;
                    int j = 0;
                    for (j = 0; j < gas_size; j++) {
                        int k = (j + i) % gas_size;
                        s = s + gas[k] - cost[k];
                        if (s < 0) {
                            break;
                        }
                    }
                    if (j == gas_size) {
                        return i;
                    }
                }
            }

            return -1;
        }
};