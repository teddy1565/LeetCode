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
            int total_gas = std::reduce(gas.begin(), gas.end(), 0);
            int total_cost = std::reduce(cost.begin(), cost.end(), 0);

            if (total_gas < total_cost) {
                return -1;
            }

            // if total_gas >= total_cost, must have resolve

            int current_gas = 0;
            int ans = 0;

            for (int i = 0; i < gas_size; i++) {
                current_gas += gas[i] - cost[i];
                if (current_gas < 0) {
                    current_gas = 0;
                    ans = i + 1;
                }
            }

            return ans;
        }
};