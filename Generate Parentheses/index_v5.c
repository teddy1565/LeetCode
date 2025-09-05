/**
 * @file index_v5.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-05
 * 
 * @copyright Copyright (c) 2025
 * 
 * I may try bitwise
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
    int bracket_size = n * 2;
    int rows_list[] = {0, 1, 2, 5, 14, 44};

    const unsigned int base_n = pow_int(2, n) - 1;

    for (int i = n; i > 1; i--) {
        const unsigned int base_nn = pow_int(2, i) - 1;
    }

    // for (int i = 0; i < n - 1; i++) {
    //     for (int j = i; j < n; j++) {
    //         printf("%d %d\n", i, j);
    //     }
    // }

    // for (int i = n; i > 1; i--) {
    //     for (int j = 0; j < i; j++) {

    //     }
    // }

    // # | 1   2   4   8   16  32  64  128     4n-1
    // ————————————————————————————————————————
    // 1 | 1   1   1   1   0   0   0   0    15  4
    // 2 | 1   1   1   0   1   0   0   0    23  6
    // 3 | 1   1   1   0   0   1   0   0    39  10
    // 4 | 1   1   1   0   0   0   1   0    71  18
    //                                      -24
    // 5 | 1   1   0   1   1   0   0   0    35  9
    // 6 | 1   1   0   1   0   1   0   0    43  11
    // 7 | 1   1   0   1   0   0   1   0    75  19
    //                                      -36
    // 8 | 1   1   0   0   1   1   0   0    51  13
    // 9 | 1   1   0   0   1   0   1   0    83  21
    //
    //                                              4n+1
    // 1 | 1   0   1   1   1   0   0   0    29  7
    // 2 | 1   0   1   1   0   1   0   0    45  11
    // 3 | 1   0   1   1   0   0   1   0    77  19
    //
    // 4 | 1   0   1   0   1   1   0   0    53  13
    // 5 | 1   0   1   0   1   0   1   0    85  21

    



    // # | 1   2   4   8   16  32  64  128  256  512
    // ————————————————————————————————————————————————————————
    // 5 | 1   1   1   1   1   0   0   0    0    0    
    //   | 1   1   1   1   0   1   0   0    0    0    
    //   | 1   1   1   1   0   0   1   0    0    0    
    //   | 1   1   1   1   0   0   0   1    0    0    
    //   | 1   1   1   1   0   0   0   0    1    0    

    // 4 | 1   1   1   0   1   1   0   0    0    0
    //   | 1   1   1   0   1   0   1   0    0    0
    //   | 1   1   1   0   1   0   0   1    0    0
    //   | 1   1   1   0   1   0   0   0    1    0

    // 3 | 1   1   1   0   0   1   1   0    0    0
    //   | 1   1   1   0   0   1   0   1    0    0
    //   | 1   1   1   0   0   1   0   0    1    0

    // 2 | 1   1   1   0   0   0   1   1    0    0
    //   | 1   1   1   0   0   0   1   0    1    0
    //   ---------------------------------------------

    // 4 | 1   1   0   1   1   1   0   0    0    0
    //   | 1   1   0   1   1   0   1   0    0    0
    //   | 1   1   0   1   1   0   0   1    0    0
    //   | 1   1   0   1   1   0   0   0    1    0
    
    // 3 | 1   1   0   1   0   1   1   0    0    0
    //   | 1   1   0   1   0   1   0   1    0    0
    //   | 1   1   0   1   0   1   0   0    1    0

    // 2 | 1   1   0   1   0   0   1   1    0    0
    //   | 1   1   0   1   0   0   1   0    1    0

    // 3 | 1   1   0   0   1   1   1   0    0    0
    //   | 1   1   0   0   1   1   0   1    0    0
    //   | 1   1   0   0   1   1   0   0    1    0

    // 2 | 1   1   0   0   1   0   1   1    0    0
    //   | 1   1   0   0   1   0   1   0    1    0

    // 2 | 1   1   0   0   0   1   1   1    0    0
    //   | 1   1   0   0   0   1   1   0    1    0

    //   ---------------------------------------------

    // 4 | 1   0   1   1   1   1   0   0    0    0
    //   | 1   0   1   1   1   0   1   0    0    0
    //   | 1   0   1   1   1   0   0   1    0    0
    //   | 1   0   1   1   1   0   0   0    1    0

    // 3 | 1   0   1   1   0   1   1   0    0    0
    //   | 1   0   1   1   0   1   0   1    0    0
    //   | 1   0   1   1   0   1   0   0    1    0

    // 3 | 1   0   1   0   1   1   1   0    0    0
    //   | 1   0   1   0   1   1   0   1    0    0
    //   | 1   0   1   0   1   1   0   0    1    0

    // 2 | 1   0   1   0   1   0   1   1    0    0
    //   | 1   0   1   0   1   0   1   0    1    0

    // 2 | 1   0   1   0   0   1   1   1    0    0
    //   | 1   0   1   0   0   1   1   0    1    0

    //   ---------------------------------------------

    // # | 1   2   4   8   16  32 
    // ————————————————————————————————————————————————————————
    //   | 1   1   1   0   0   0
    //   | 1   1   0   1   0   0
    //   | 1   1   0   0   1   0

    //   | 1   0   1   1   0   0
    //   | 1   0   1   0   1   0




    unsigned int base = base_n;
    for (int i = 0, base_i = i % n; i < max_rows; i++, base_i = i%n, base+=(n << base_i)) {
        printf("%d\n", base);
        if (i > 0 && (((i % n) + ((i / n) * n)) % n == 0)) {
            base = 35;
            // printf("%d %d %d\n", i, base_i, base);
        }
        // printf("%d %d | %d | %d\n", i % n, i / n, base, max_rows - ((i / n) * n));
        for (int j = 0; j < bracket_size; j++) {
            
            int index = (base >> j) & 1;
            // printf("%d ", index);
            // printf("%c", bracket_dict[]);
        }
        printf("\n");
    }
    
    // for (int i = 0; i < max_rows; i++) {
    //     int bits = (right_base_n << (i % n));
    //     int right = (right_base_n << (i % n));
    //     int left = (((left_base_n << 0) - (left_base_n >> (i % n))) << ((i % n) % (n - 1)));
    //     for (int j = 0; j < brack_len; j++) {
    //         int index = (bits >> j) & 1;
    //         // printf("%d %d | %d\n", base_bit, offset_bit, index);
    //         printf("%c", bracket_dict[index]);
    //     }
    //     printf("\n");
    // }

    // printf("%d\n", base_n);

    return NULL;

}

int main(void) {
    int returnSize = 0;
    generateParenthesis(4, &returnSize);
    return 0;
}