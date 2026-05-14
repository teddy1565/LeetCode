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
#include <unordered_set>
#include <charconv>

class Solution {
    private:
        static void helper(std::stack<int> & nums_stack, char op) {
            int x = nums_stack.top(); nums_stack.pop();
            int y = nums_stack.top(); nums_stack.pop();
            switch (op) {
                case '+':
                    nums_stack.push(x + y);
                    break;
                case '-':
                    nums_stack.push(y - x);
                    break;
                case '*':
                    nums_stack.push(x * y);
                    break;
                case '/':
                    nums_stack.push(y / x);
                    break;
                default:
                    break;
            }
        }
    public:
        int evalRPN(std::vector<std::string>& tokens) {
            int n = tokens.size();
            std::stack<int> nums_stack;
            

            for (int i = 0; i < n; i++) {

                if (tokens[i][0] - '0' < 0 && tokens[i][1] == '\0') {
                    helper(nums_stack, tokens[i][0]);
                    continue;
                }

                int k = 0;
                #if _LIBCPP_STD_VER >= 17
                    std::from_chars(&tokens[i][0], &tokens[i][0]+(tokens[i].size()), k);
                #else
                    k = std::stoi(tokens[i]);
                #endif
                nums_stack.push(k);
            }

            if (nums_stack.empty()) {
                return 0;
            }
            return nums_stack.top();
        }
};