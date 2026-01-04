/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int row_size = matrixSize;
    int col_size = matrixColSize[0];
    // [0, 0], [0, 1], [0, 2], [1, 2], [2, 2], [2, 1], [1, 1]
    
    int element_size = row_size * col_size;
    (*returnSize) = element_size;
    int element_index = 0;
    
    int *ans = (int *) malloc(sizeof(int) * element_size);
    int a = 0;
    int b = row_size - 1;
    int c = col_size - 1;
    int d = 0;

    int row_start = 0;
    int row_end = row_size;
    int col_start = 0;
    int col_end = col_size;
    while (element_index < element_size) {
        
        for (int i = col_start; i < col_end && element_index < element_size; i++) {
            // printf("a: %d %d\n", element_index, matrix[row_start][i]);
            ans[element_index++] = matrix[row_start][i];
        }
        for (int i = row_start + 1; i < row_end - 1 && element_index < element_size; i++) {
            // printf("b: %d %d\n", element_index, matrix[i][col_end-1]);
            ans[element_index++] = matrix[i][col_end-1];
        }
        for (int i = col_end - 1; i >= col_start && element_index < element_size; i--) {
            // printf("c: %d %d\n", element_index, matrix[row_end - 1][i]);
            ans[element_index++] = matrix[row_end - 1][i];
        }
        for (int i = row_end - 2; i >= row_start + 1 && element_index < element_size; i--) {
            // printf("d: %d %d\n", element_index, matrix[i][col_start]);
            ans[element_index++] = matrix[i][col_start];
        }
        row_start += 1;
        col_start += 1;
        row_end -= 1;
        col_end -= 1;
    }

    return ans;
}