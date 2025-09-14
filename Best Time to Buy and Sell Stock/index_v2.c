/**
 * @file index_v2.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-14
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "index.h"

int maxProfit(int* prices, int pricesSize) {

    if (pricesSize == 0 || pricesSize == 1) {
        return 0;
    } else if (pricesSize == 2 && prices[0] < prices[1]) {
        return prices[1] - prices[0];
    } else if (pricesSize == 2 && prices[0] >= prices[1]) {
        return 0;
    }

    int buy_min = prices[0];
    int sell_max_index = 1;
    int answer = 0;

    for (int i = 1; i < pricesSize; i++) {
        if (prices[i] > prices[sell_max_index]) {
            sell_max_index = i;
        }
    }

    for (int i = 0; i < pricesSize - 1; i++) {
        if (i > 0 && prices[i] >= buy_min) {
            continue;
        } else if (prices[i] >= prices[sell_max_index]) {
            continue;
        } else if (i >= sell_max_index) {
            sell_max_index = i + 1;
            for (int j = i + 1; j < pricesSize; j++) {
                if (prices[j] > prices[sell_max_index]) {
                    sell_max_index = j;
                }
            }
        } 

        int temp = prices[sell_max_index] - prices[i];
        if (temp > answer) {
            answer = temp;
        }
    }

    
    return answer;
}

int main(void) {

    printf("answer: %d\n", maxProfit(test_case_01, test_case_01_length));
    printf("answer: %d\n", maxProfit(test_case_02, test_case_02_length));
    printf("answer: %d\n", maxProfit(test_case_03, test_case_03_length));
    printf("answer: %d\n", maxProfit(test_case_04, test_case_04_length));
    return 0;
}