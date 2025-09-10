/**
 * @file index_v6.c
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

    int overflow = 0;
    for (int i = 0; i < 30; i++) {
        if ((2 << i) == divisor || divisor == INT_MAX) {
            overflow = 1;
            break;
        }
    }
    if (dividend == -2147483648) {
        if (divisor < 0) {
            overflow = 1;
        }
        dividend = -2147483647;
    }

    int a = abs(dividend);
    long long int b = abs(divisor);
    int m = 0;
    int answer = 0;


    for (int c = 0; c < 31 && (((b << c) & INT_MIN) == 0); c++) {
        if ((int)(b << c) > a) {
            break;
        }
        m = c;
    }

    while (a-b >= 0) {
        for (int c = m; c >= 0 && a > 0; c--) {
            if ((a - (b << c)) >= 0) {
                answer += (1 << c);
            } else if ((a - (b << c)) < 0) {
                continue;
            }
            a = a - (b << c);
        }
    }
    
    if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0)) {
        return (-answer) ^ overflow;
    }
    return answer;
}

int main(void) {
    printf("%d\n", divide(10000, 3));
    printf("%d\n", divide(7, -3));
    printf("%d\n", divide(2147483647, 3));
    printf("%d\n", divide(2147483647, 2147483646));
    // printf("%d\n", divide(2147483647, 2));
    return 0;
}