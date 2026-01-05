#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>


void grid_bfs(char** grid, int row_size, int col_size, int p_index_x, int p_index_y) {
    if (p_index_x < 0 || p_index_x >= row_size || p_index_y < 0 || p_index_y >= col_size || grid[p_index_x][p_index_y] != '1') {
        return;
    }
    grid[p_index_x][p_index_y] = '0';
    grid_bfs(grid, row_size, col_size, p_index_x + 1, p_index_y);
    grid_bfs(grid, row_size, col_size, p_index_x - 1, p_index_y);
    grid_bfs(grid, row_size, col_size, p_index_x, p_index_y + 1);
    grid_bfs(grid, row_size, col_size, p_index_x, p_index_y - 1);
}

int numIslands(char** grid, int gridSize, int* gridColSize) {
    
    int island_count = 0;
    int row_size = gridSize;
    int col_size = gridColSize[0];
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            if (grid[i][j] == '1') {
                grid_bfs(grid, row_size, col_size, i, j);
                island_count += 1;
            }
        }
    }
    return island_count;
}