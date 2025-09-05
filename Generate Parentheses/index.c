/**
 * @file index.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-09-05
 * 
 * @copyright Copyright (c) 2025
 * 
 */

#include "index.h"

const char bracket_dict[2] = { '(', ')' };

/**
 * @brief catalan number
 * 
 */
const int rows_list[8] = { 1, 2, 5, 14, 42, 132, 429, 1430 };

void generate_parenthesis(char **s, int *row_index, unsigned int bit_wise_n, int n, int left_n, int right_n) {
    if (left_n > n || right_n > n || left_n < right_n) {
        return ;
    } else if (left_n == n && right_n == n) {
        bit_wise_n = bit_wise_n >> 1;
        
        for (int i = 0; i < (n*2); i++) {
            s[*row_index][i] = bracket_dict[(bit_wise_n >> i) & 1];
        }
        (*row_index) = (*row_index) + 1;
    }

    generate_parenthesis(s, row_index, ((bit_wise_n + 1) << 1), n, left_n + 1, right_n);
    generate_parenthesis(s, row_index, (bit_wise_n << 1), n, left_n, right_n + 1);
}

char** generateParenthesis(int n, int* returnSize) {

    *returnSize = rows_list[n - 1];
    int bracket_size = n * 2;

    char **ans = (char **) malloc(sizeof(char*) * (*returnSize));
    
    for (int i = 0; i < *returnSize; i++) {
        ans[i] = (char *) malloc(sizeof(char) * (bracket_size + 1));
        memset(ans[i], 0, sizeof(char) * (bracket_size + 1));
        
    }

    unsigned int bit_wise_n = 0;
    int row_index = 0;
    generate_parenthesis(ans, &row_index, bit_wise_n, n, 0, 0);

    return ans;
}

int main(void) {
    int returnSize = 0;
    generateParenthesis(5, &returnSize);
    return 0;
}