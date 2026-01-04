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
    int x = 0;
    int y = 0;
    int x_top_edge = 0;
    int x_bottom_edge = row_size;
    int y_right_edge = col_size - 1;
    int y_left_edge = 0;
    
    int *ans = (int *) malloc(sizeof(int) * element_size);
    
    while (element_index < element_size) {
        ans[element_index] = matrix[x][y];
        element_index += 1;
    }

    return ans;
}