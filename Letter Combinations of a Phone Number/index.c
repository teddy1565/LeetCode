#include "index.h"


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

    printf("%d %d %d\n", total, rows, cols);

    answer = (char **) malloc(sizeof(char *) * total);
    for (int i = 0; i < total; i++) {
        answer[i] = (char *) malloc(sizeof(char) * (digits_size + 1));
        memset(answer[i], 0, (sizeof(char) * (digits_size + 1)));
    }

    printf("i j | r c | br bc |\ttotal rows cols\n");
    printf("--------------------------------\n\n");

    for (int i = 0; i < total; i++) {
        int k = 0;
        for (int j = 0; j < digits_size; j++) {
            int key_board_row = digits[j] - CHR_OFFSET;
            int key_board_col = ((i*j) % total);
            int back_trace_cols = key_board_col / cols;
            int back_trace_rows = key_board_col / rows;

            

            if (back_trace_cols > 0) {
                int c = back_trace_cols % digits_length_map[key_board_row];
                key_board_col = key_board_col % cols;
                answer[i][j - 1] = key_board[digits[j-1] - CHR_OFFSET][c];
            }

            if (back_trace_rows > 0) {
                int c = (((i * (j - 1)) % total) + back_trace_rows);
                key_board_col = (key_board_col + back_trace_cols) % digits_length_map[j];
                answer[i][j - 1] = key_board[digits[j-1] - CHR_OFFSET][c];
                
            }

            answer[i][j] = key_board[key_board_row][key_board_col];
            printf("%d %d | %d %d | %d %d | %d %d %d | %c\n", i, j, key_board_row, key_board_col, back_trace_rows, back_trace_cols, total, rows, cols, answer[i][j]);
        }
        printf("\n");
    }





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
    letterCombinations("234", &return_size);
    return 0;
}