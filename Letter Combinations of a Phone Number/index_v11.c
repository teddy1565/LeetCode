/**
 * @file index_v10.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-31
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "index.h"

#define DEBUG


#define CHR_OFFSET 50

const int digits_length_map[8] = { 3, 3, 3, 3, 3, 4, 3, 4 };
const char key_board_head_map[8] = { 'a', 'd', 'g', 'j', 'm', 'p', 't', 'w' };

// const char key_board[8][5] = {
//     { 'a', 'b', 'c', '\0', '\0' },
//     { 'd', 'e', 'f', '\0', '\0' },
//     { 'g', 'h', 'i', '\0', '\0' },
//     { 'j', 'k', 'l', '\0', '\0' },
//     { 'm', 'n', 'o', '\0', '\0' },
//     { 'p', 'q', 'r', 's' , '\0'},
//     { 't', 'u', 'v', '\0', '\0'},
//     { 'w', 'x', 'y', 'z' , '\0'}
// };

static int integer_pow(int a, int b) {
    int c = 1;
    for (int i = 0; i < b; i++) {
        c = c * a;
    }
    return c;
}


char** letterCombinations(char* digits, int* returnSize) {
    
    char **answer;
    int digits_size = strlen(digits);
    if (digits_size == 0) {
        *returnSize = 0;
        return answer;
    }

    int total = 1;
    int rows = 1;

    for (int i = 0; i < digits_size; i++) {
        if (i > 0) {
            rows = rows * digits_length_map[digits[i] - CHR_OFFSET];
        }
        total = total * digits_length_map[digits[i] - CHR_OFFSET];
    }

    *returnSize = total;

    int cols = total / rows;

    answer = (char **) malloc(sizeof(char *) * total);
    for (int i = 0; i < total; i++) {
        answer[i] = (char *) malloc(sizeof(char) * (digits_size + 1));
        memset(answer[i], 0, (sizeof(char) * (digits_size + 1)));
    }

    for (int i = digits_size - 1, m = digits_size - i; i >= 0; i--) {
        int key_index = digits[i] - CHR_OFFSET;
        
        for (int j = 0; j < total; j++) {
            int k = (j / m) % digits_length_map[key_index];
            answer[j][i] = key_board_head_map[key_index] + k;
        }
        m = m * digits_length_map[key_index];
    }
    return answer;
}

int main(void) {
    int return_size = 0;
    // printf("2\n");
    // printf("\t%d %d %d\n", 'a', 'b', 'c');

    // printf("3\n");
    // printf("\t%d %d %d\n", 'd', 'e', 'f');

    // printf("4\n");
    // printf("\t%d %d %d\n", 'g', 'h', 'i');

    // printf("5\n");
    // printf("\t%d %d %d\n", 'j', 'k', 'l');

    // printf("6\n");
    // printf("\t%d %d %d\n", 'm', 'n', 'o');

    // printf("7\n");
    // printf("\t%d %d %d %d\n", 'p', 'q', 'r', 's');

    // printf("8\n");
    // printf("\t%d %d %d\n", 't', 'u', 'v');

    // printf("9\n");
    // printf("\t%d %d %d %d\n", 'w', 'x', 'y', 'z');


    // letterCombinations("7239", &return_size);

    // letterCombinations("23", &return_size);
    letterCombinations("2", &return_size);
    // letterCombinations("5678", &return_size);
    // letterCombinations("234", &return_size);
    return 0;
}