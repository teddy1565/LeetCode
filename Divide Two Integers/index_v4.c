/**
 * @file index_v3.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-10
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "index.h"


int divide(int dividend, int divisor) {

    if (dividend == INT_MIN && divisor == -1) {
        return INT_MAX;
    } else if (dividend == INT_MIN && divisor == 1) {
        return INT_MIN;
    } else if (dividend == INT_MIN && divisor == INT_MIN) {
        return 1;
    } else if (divisor == INT_MIN) {
        return 0;
    } else if (divisor == 2) {
        return (dividend >> 1);
    } else if (divisor == -2) {
        return -(dividend >> 1);
    } else if (dividend == INT_MIN) {
        if (divisor < -1073741824) {
            return 1;
        } else if (divisor < -715827882) {
            return 2;
        } else if (divisor > 1073741824) {
            return -1;
        } else if (divisor > 715827882) {
            return -2;
        }
    } else if (dividend >= 0 && divisor > 0 && dividend < divisor) {
        return 0;
    } else if (dividend < 0 && divisor < 0 && dividend > divisor) {
        return 0;
    } else if (dividend == 0) {
        return 0;
    } else if (divisor == 1) {
        return dividend;
    } else if (divisor == -1) {
        return -dividend;
    } else if (dividend == divisor) {
        return 1;
    } else if ((dividend != -2147483648 && -dividend == divisor) || (divisor != -2147483648 && dividend == -divisor)) {
        return -1;
    } else if (abs(dividend) < abs(divisor)) {
        return 0;
    }

    if (dividend == -2147483648) {
        dividend = -2147483647;
    }
    int a = abs(dividend);
    int b = abs(divisor);
    int answer = 0;

    for (int c = 0; c < 31; c ++) {
        int n = 0;
        for (int j = 0; j < (1 << c); j++) {
            n += abs(divisor);
        }
    }

    for (int c = 30; c >= 0; c--) {
        int n = (1 << c);
        if (n > a) {
            continue;
        }
        int k = 0;
        while (b - n >= 0) {
            b = b - n;
            k++;
        }
        // long long int k = 0;
        // for (int j = 0; j < (abs(divisor)); j++) {
        //     if (((k + n) & (INT_MIN)) != 0) {
        //         k = 0;
        //         break;  // overflow
        //     }
        //     k = k + n;
        // }
        // printf("\t1 << %d: %d\t%d\n", c, (1 << c), a);
        while ((a - n) >= 0) {
            a = a - n;
            // answer = answer - (1 << c);
        }
        
    }

    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
        return -answer;
    }
    return answer;
}

int main(void) {
    // printf("%d\n", divide(10000, 3));
    // printf("%d\n", divide(7, -3));
    // printf("%d\n", divide(2147483647, 3));
    printf("%d\n", divide(2147483647, 2147483646));
    // printf("%d\n", divide(2147483647, 2));
    return 0;
}