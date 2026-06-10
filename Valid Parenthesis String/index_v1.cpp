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

/**
 * ((*))
 * (((())*))
 * 
 * ((*)
 * *)*)
 */

class Solution {
    public:
        bool checkValidString(std::string s) {
            std::stack<int> brack_stack;
            std::stack<int> star_stack;

            int size = s.size();

            for (int i = 0; i < size; i++) {
                if (s[i] == '*') {
                    star_stack.push(i);
                } else if (s[i] == '(') {
                    brack_stack.push(i);
                } else if (s[i] == ')') {
                    if (!brack_stack.empty()) {
                        int left_brack_index = brack_stack.top();
                        if (left_brack_index < i) {
                            brack_stack.pop();
                            continue;
                        }
                    }

                    if (!star_stack.empty()) {
                        int star_index = star_stack.top();
                        if (star_index < i) {
                            star_stack.pop();
                            continue;
                        }
                    }

                    return false;
                }
            }

            std::stack<int> reverse_star_stack;
            std::stack<int> reverse_brack_stack;
            while (!star_stack.empty()) {
                int i = star_stack.top();
                star_stack.pop();
                reverse_star_stack.push(i);
            }

            while (!brack_stack.empty()) {
                int i = brack_stack.top();
                brack_stack.pop();
                reverse_brack_stack.push(i);
            }

            if (reverse_star_stack.size() < reverse_brack_stack.size()) {
                return false;
            }

            while(!reverse_star_stack.empty() && !reverse_brack_stack.empty()) {
                int star_index = reverse_star_stack.top();
                reverse_star_stack.pop();

                int brack_index = reverse_brack_stack.top();
                if (star_index > brack_index) {
                    reverse_brack_stack.pop();
                }
            }

            return reverse_brack_stack.size() <= reverse_star_stack.size();
        }
};