#include "index.h"

int** transpose(int** matrix, int matrixSize, int* matrixColSize, int* returnSize, int** returnColumnSizes) {
    int row_size = matrixSize;
    int col_size = matrixColSize[matrixSize - 1];
    (*returnSize) = col_size;
    free(*returnColumnSizes);
    (*returnColumnSizes) = (int *) malloc(sizeof(int) * col_size);
    memset((*returnColumnSizes), 0, sizeof(int) * col_size);

    int **answer = (int **) malloc(sizeof(int *) * col_size);
    for (int i = 0; i < col_size; i++) {
        answer[i] = (int *) malloc(sizeof(int) * row_size);
        memset(answer[i], 0, sizeof(int) * row_size);
        (*returnColumnSizes)[i] = row_size;
    }
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            answer[j][i] = matrix[i][j];
        }
    }

    return answer;
}

int main(void) {
    return 0;
}