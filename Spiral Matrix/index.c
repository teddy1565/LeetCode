/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {

    // [0, 0], [0, 1], [0, 2], [1, 2], [2, 2], [2, 1], [1, 1]
    
    (*returnSize) = matrixSize * matrixColSize[0];
    int element_index = 0;
    
    int *ans = (int *) malloc(sizeof(int) * (*returnSize));

    int row_start = 0;
    int row_end = matrixSize;
    int col_start = 0;
    int col_end = matrixColSize[0];
    while (element_index < (*returnSize)) {
        
        for (int i = col_start; i < col_end && element_index < (*returnSize); i++) {
            ans[element_index++] = matrix[row_start][i];
        }
        for (int i = row_start + 1; i < row_end - 1 && element_index < (*returnSize); i++) {
            ans[element_index++] = matrix[i][col_end-1];
        }
        for (int i = col_end - 1; i >= col_start && element_index < (*returnSize); i--) {
            ans[element_index++] = matrix[row_end - 1][i];
        }
        for (int i = row_end - 2; i >= row_start + 1 && element_index < (*returnSize); i--) {
            ans[element_index++] = matrix[i][col_start];
        }
        row_start += 1;
        col_start += 1;
        row_end -= 1;
        col_end -= 1;
    }

    return ans;
}