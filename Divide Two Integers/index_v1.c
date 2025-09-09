/**
 * @file index_v1.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-09
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "index.h"


int divide(int dividend, int divisor) {
    int is_negative = 0;
    if (dividend < 0 && divisor < 0) {
        is_negative = 0;
    } else if (dividend > 0 && divisor > 0) {
        is_negative = 0;
    } else if (dividend < 0 || divisor < 0) {
        is_negative = 1;
    }

    int a = abs(dividend);
    int b = abs(divisor);

    if (a < b) {
        return 0;
    } else if (a == b && is_negative == 0) {
        return 1;
    } else if (a == b && is_negative == 1) {
        return -1;
    } else if (b == 1 && is_negative == 1) {
        return -a;
    } else if (b == 1 && is_negative == 0) {
        return a;
    }
    int n = 0;
    int c = 0;
    while (a > 0) {
        while((b << c) < a) {
            if ((b << c) < (b << c - 1)) {
                break;
            }
            c++;
        }
        if (c == 0) {
            break;
        }
        int k = 1;
        for (int i = 1; i <= (c - 1); i++) {
            for (int j = 0; j < i; j++) {
                k *= b;
            }
        }
        printf("\t\tc: %d\n", c);
        printf("\tk: %d\n", k);
        a = (a - (b << (c - 1)));
        c = 0;
    }
    
        printf("\t%d\n", n);
    return n;
}

int main(void) {
    printf("%d\n", divide(60, 60));
    printf("%d\n", divide(2147483647, 1));
    printf("%d\n", divide(2147483647, 2));
    // printf("%d\n", divide(2147483647, -1));
    // printf("%d\n", divide(2147483647, -2147483648));
    return 0;
}