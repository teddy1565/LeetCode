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
        if (prices[i] <= buy_min) {
            buy_min = prices[i];
        } else {
            if (prices[i] - buy_min > answer) {
                answer = prices[i] - buy_min;
            }
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