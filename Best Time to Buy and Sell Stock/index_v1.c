/**
 * @file index_v1.c
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
    printf("------------------------\n");
    if (pricesSize < 10) {
        for (int i = 0; i < pricesSize; i++) {
            printf("%d ", prices[i]);
        }
        printf("\n");
    }

    if (pricesSize == 0 || pricesSize == 1) {
        return 0;
    }

    int buy_min = prices[pricesSize - 2];
    int sell_max = prices[pricesSize - 1];
    int answer = 0;

    for (int i = pricesSize-2; i >= 0; i--) {   // buy
        if (prices[i] > buy_min) {
            continue;
        }
        for (int j = i + 1; j < pricesSize; j++){   // sell
            if ((prices[i] - prices[j]) < answer) {
                answer = prices[i] - prices[j];
                buy_min = prices[i];
                sell_max = prices[j];
            }
        }
    }

    printf("%d %d\n", buy_min, sell_max);

    return -answer;
}

int main(void) {

    printf("answer: %d\n", maxProfit(test_case_01, test_case_01_length));
    printf("answer: %d\n", maxProfit(test_case_02, test_case_02_length));
    printf("answer: %d\n", maxProfit(test_case_03, test_case_03_length));
    printf("answer: %d\n", maxProfit(test_case_04, test_case_04_length));
    return 0;
}