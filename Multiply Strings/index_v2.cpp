#include <vector>
#include <queue>
#include <string>
#include <iostream>

class Solution {
    public:
        std::string multiply(std::string num1, std::string num2) {
            if (num1 == "0" || num2 == "0") {
                return "0";
            }
            std::vector<int> num(num1.size() + num2.size(), 0);

            for(int i = num1.size() - 1; i >= 0; i--) {
                for (int j = num2.size() - 1; j >= 0; j--) {
                    num[i + j + 1] += (num1[i] - '0') * (num2[j] - '0');
                    num[i + j] += num[i + j + 1] / 10;
                    num[i + j + 1] %= 10;
                }
            }

            int skip_i = 0;
            while (skip_i < num.size() && num[skip_i] == 0) {
                skip_i += 1;
            }

            std::string ans = "";
            while (skip_i < num.size()) {
                ans.push_back(num[skip_i++] + '0');
            }

            return ans;
        }
};