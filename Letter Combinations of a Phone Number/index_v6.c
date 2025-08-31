/**
 * @file index_v6.c
 * @author JING TING XIONG (teddy1565@gmail.com)
 * @brief 
 * @version 0.1
 * @date 2025-08-28
 * 
 * @copyright Copyright (c) 2025
 * 
 * 感覺方向不對
 * 
 */
#include "index.h"

#define DEBUG


#define CHR_OFFSET 50

const int digits_length_map[8] = { 3, 3, 3, 3, 3, 4, 3, 4 };

const char key_board[8][5] = {
    { 'a', 'b', 'c', '\0', '\0' },
    { 'd', 'e', 'f', '\0', '\0' },
    { 'g', 'h', 'i', '\0', '\0' },
    { 'j', 'k', 'l', '\0', '\0' },
    { 'm', 'n', 'o', '\0', '\0' },
    { 'p', 'q', 'r', 's' , '\0'},
    { 't', 'u', 'v', '\0', '\0'},
    { 'w', 'x', 'y', 'z' , '\0'}
};


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

    #ifdef DEBUG
    printf("%d %d %d %d\n", digits_size, total, rows, cols);
    printf("----------------\n");
    #endif

    answer = (char **) malloc(sizeof(char *) * total);
    for (int i = 0; i < total; i++) {
        answer[i] = (char *) malloc(sizeof(char) * (digits_size + 1));
        memset(answer[i], 0, (sizeof(char) * (digits_size + 1)));
    }

    for (int i = digits_size-1; i>=0; i--) {
        int key_board_row = digits[i] - CHR_OFFSET;
        for (int j = 0, m = 1; j < digits_length_map[key_board_row]; j++, m++) {

            

            //g = i - (x / total)
            for (int x = rows * (m - 1), k = 0; x < (rows * m); x++, k++) {


                printf("%d ", ((x / rows) + k) % digits_size);

                // k = ((x / rows) + k) % digits_size;

                // printf("%d %d %d %d\t|\t", m, i, j, i*j);
                // printf("%d ", m-j);
                
                // if (k > (i) || i == 0) {
                //     k = 0;
                // }
                // printf("%c", key_board[key_board_row][(j + ((x / rows) + k) % digits_length_map[key_board_row]) % digits_length_map[key_board_row]]);
                // printf("%d %d %d | %d %d | %d\n", x, i, key_board_row, j, k, (j + k) % digits_length_map[key_board_row]);
                answer[x][i] = key_board[key_board_row][(j + k) % digits_length_map[key_board_row]];
                // answer[x][i] = key_board[key_board_row][(j + ((x / rows) + k)) % digits_length_map[key_board_row]];
            }

            
            printf("\n");
        }
        printf("\n");
    }



    printf("====================\n");
    printf("%d %d\n", total, digits_size);
    for (int i = 0; i < total; i++) {
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


    // letterCombinations("7239", &return_size);
    letterCombinations("23", &return_size);
    return 0;
}