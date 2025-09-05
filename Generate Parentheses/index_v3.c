/**
 * @file index_v3.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-04
 * 
 * @copyright Copyright (c) 2025
 * 
 * i think binary >> & << maybe can use
 */
#include "index.h"

const char bracket_dict[2] = { '(', ' ' };


int pow_int(int x, int y) {
    if (x == 0) {
        return 0;
    } else if (y == 0) {
        return 1;
    }

    int k = 1;
    for (int i = 0; i < y; i++) {
        k = k * x;
    }

    return k;

}

void printBits(int n) {
    // 假設是 32 位元整數，從第 31 位開始
    for (int i = 31; i >= 0; i--) {
        // 使用右移運算符將第 i 個位元移到最右邊
        int bit = (n >> i) & 1;
        printf("%d ", bit); // 印出該位元
    }
    printf("\n");
}

int merge_n(const int base_n, const int n, const int len) {
    for (int i = 0; i < len; i++) {
        int bit = (n >> i) & 1;
        printf("%d ", bit);
    }
}

char** generateParenthesis(int n, int* returnSize) {
    int max_rows = 2 << n;
    int brack_len = n * 2;

    const int base_n = pow_int(2, n*2) - 1;
    int offset_n = pow_int(2, n) - 1;

    
    for (int i = 0; i < max_rows; i++) {
        int offset = (offset_n << i) + i;
        for (int j = 0; j < brack_len; j++) {
            int base_bit = (base_n >> j) & 1;
            int offset_bit = (offset >> j) & 1;
            
            int index = (base_bit + (offset_bit)) % 2;

            // printf("%d %d | %d\n", base_bit, offset_bit, index);
            printf("%c", bracket_dict[index]);
        }
        printf("\n");
    }

    // printf("%d\n", base_n);

    return NULL;

}

int main(void) {
    int returnSize = 0;
    generateParenthesis(4, &returnSize);
    return 0;
}