#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    
    for (int i = 0; i < 9; i++) {
        int row_check[10] = { 0 };
        int col_check[10] = { 0 };
        int s_check[10] = { 0 };
        for (int j = 0; j < 9; j++) {
            if (board[i][j] != '.') {
                row_check[board[i][j] - 48] += 1;
                if (row_check[board[i][j] - 48] > 1) {
                    return false;
                }
            }
            
            if (board[j][i] != '.') {
                col_check[board[j][i] - 48] += 1;
                if (col_check[board[j][i] - 48] > 1) {
                    return false;
                }
            }

            

            int s_block_row = (i / 3) * 3;
            int s_block_col = (i % 3) * 3;
            int s_row = j / 3;
            int s_col = j % 3;
            if (board[s_block_row + s_row][s_block_col + s_col] != '.') {
                s_check[board[s_block_row + s_row][s_block_col + s_col] - 48] += 1;
                if (s_check[board[s_block_row + s_row][s_block_col + s_col] - 48] > 1) {
                    return false;
                }
            }
        }
    }

    return true;
}