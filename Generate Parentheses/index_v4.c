/**
 * @file index_v4.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-04
 * 
 * @copyright Copyright (c) 2025
 * 
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

unsigned int merge_n(const int base_n, const int n, const int len) {
    unsigned int ans = 0;
    for (int i = 0; i < len; i++) {
        int n_bit = (n >> i) & 1;
        int base_n_bit = (base_n >> i) & 1;
        int bit = (n_bit + base_n_bit)%2;
        ans = ans << 1;
        ans = ans + bit;
    }
}

char** generateParenthesis(int n, int* returnSize) {

    int max_rows = 2 << n;
    int brack_len = n * 2;

    

    
    // unsigned int offset_n = pow_int(2, n) - 1;
    const unsigned int right_base_n = pow_int(2, n*2) - pow_int(2, n);
    const unsigned int left_base_n = pow_int(2, n) - 1;
    // const unsigned base_n = pow_int(2, n) - 1;

    
    for (int i = 0; i < max_rows; i++) {
        int bits = (right_base_n << (i % n));
        int right = (right_base_n << (i % n));
        int left = (((left_base_n << 0) - (left_base_n >> (i % n))) << ((i % n) % (n - 1)));
        for (int j = 0; j < brack_len; j++) {
            int index = (bits >> j) & 1;
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