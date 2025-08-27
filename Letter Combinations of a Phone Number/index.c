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


char** letterCombinations(char* digits, int* returnSize) {
    
    char **answer;
    int digits_size = strlen(digits);
    if (digits_size == 0) {
        *returnSize = 0;
        return answer;
    }

    int rows = 1;
    int cols = 1;

    for (int i = 0; i < digits_size; i++) {
        if (i > 0) {
            cols = cols * digits_length_map[digits[i] - CHR_OFFSET];
        }
        rows = rows * digits_length_map[digits[i] - CHR_OFFSET];
    }

    printf("%d %d\n", rows, cols);

    answer = (char **) malloc(sizeof(char *) * rows);
    for (int i = 0; i < rows; i++) {
        answer[i] = (char *) malloc(sizeof(char) * (digits_size + 1));
        memset(answer[i], 0, (sizeof(char) * (digits_size + 1)));
    }




    // for (int i = 0; i < rows; i++) {
    //     for (int j = 0; j < digits_size; j++) {
    //         printf("%c", answer[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("----------------\n");

    
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
    letterCombinations("2739", &return_size);
    return 0;
}