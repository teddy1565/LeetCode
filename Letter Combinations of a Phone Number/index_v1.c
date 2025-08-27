/**
 * @file index_v1.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-28
 * 
 * @copyright Copyright (c) 2025
 * 
 */
#include "index.h"

#define CHR_OFFSET 50
const int digits_length_map[8] = { 3, 3, 3, 3, 3, 4, 3, 4 };

const char key_board[8][4] = {
    { 'a', 'b', 'c' },
    { 'd', 'e', 'f' },
    { 'g', 'h', 'i' },
    { 'j', 'k', 'l' },
    { 'm', 'n', 'o'},
    { 'p', 'q', 'r', 's'},
    { 't', 'u', 'v'},
    { 'w', 'x', 'y', 'z'}
};

const char key_board_w[4][8] = {
    { 'a', 'd', 'g', 'j', 'm', 'p', 't', 'w' },
    { 'b', 'e', 'h', 'k', 'n', 'q', 'u', 'x' },
    { 'c', 'f', 'i', 'l', 'o', 'r', 'v', 'y' },
    { '\0','\0','\0','\0','\0','s', '\0', 'z' },
};

// 00
// 10
// 20

// 00
// 10
// 21

// 00
// 10
// 22

// 01
// 10
// 20

char** letterCombinations(char* digits, int* returnSize) {
    
    char **answer;
    int digits_size = strlen(digits);
    if (digits_size == 0) {
        *returnSize = 0;
        return answer;
    }

    int rows = 1;

    for (int i = 0; i < digits_size; i++) {
        rows = rows * digits_length_map[digits[i] - CHR_OFFSET];
    }

    answer = (char **) malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++) {
        answer[i] = (char *) malloc(sizeof(char) * (digits_size + 1));
        memset(answer[i], 0, (sizeof(char) * (digits_size + 1)));
        
    }



    // for (int i = 0; i < rows; i++) {
    for (int j = 0; j < digits_size; j++) {
        int key_index = digits[j] - CHR_OFFSET;
        for (int k = 0, sum = 0; k < digits_length_map[key_index]; k++) {
            for (int i = sum; i < sum + digits_length_map[key_index]; i++) {
                answer[i][j] = key_board[key_index][k];
                printf("%c | %d %d | %d %d\n", key_board[key_index][k], i, j, key_index, k);
            }
            sum = sum + digits_length_map[key_index];
        }
        
        printf("==----==\n");
    }
    // }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < digits_size; j++) {
            printf("%c", answer[i][j]);
        }
        printf("\n");
    }

    printf("----------------\n");

    
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


    letterCombinations("23", &return_size);
    return 0;
}