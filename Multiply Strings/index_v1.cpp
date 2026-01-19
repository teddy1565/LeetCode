#include <vector>
#include <queue>
#include <string>
#include <iostream>

class Solution {
    public:
        std::string multiply(std::string num1, std::string num2) {
            std::string result = "";
            std::vector<std::string> num_ans_list;
            int offset = 0;
            int max_str_size = 0;
            for (int i = num1.size() - 1; i >= 0; i--) {
                std::string num_ans_tmp = "";
                num_ans_tmp.append(offset, '0');
                int k = 0;
                int n = num1[i] - '0';
                for (int j = num2.size() - 1; j >= 0; j--) {
                    int m = num2[j] - '0';
                    int x = (n * m) + k;
                    k = x / 10;
                    char y = (x % 10) + '0';
                    num_ans_tmp = y + num_ans_tmp;
                }
                char y = k + '0';
                num_ans_tmp = y + num_ans_tmp;
                num_ans_list.push_back(num_ans_tmp);
                if (num_ans_tmp.size() > max_str_size) {
                    max_str_size = num_ans_tmp.size();
                }
                offset += 1;
            }

            int b = 0;
            for (int i = 0; i < max_str_size; i++) {
                int k = 0;
                for (int j = 0; j < num_ans_list.size(); j++) {
                    int str_length = num_ans_list[j].size();
                    if (str_length > 0) {
                        k += num_ans_list[j][str_length - 1] - '0';
                        num_ans_list[j].pop_back();
                    }
                }
                int n = k + b;
                int m = n % 10;
                b = n / 10;
                char z = m + '0';
                result = z + result;
            }
            while (b > 0) {
                int n = b % 10;
                b = b / 10;
                char z = n + '0';
                result = z + result;
            }

            for (int i = 0; i < result.size(); i++) {
                if (result[i] != '0' || i == result.size() - 1) {
                    result = result.substr(i);
                    break;
                }
            }

            return result;
        }
};