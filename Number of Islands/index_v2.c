#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#define TABLE_SIZE 90000

void grid_bfs(char** grid, int row_size, int col_size, int p_index_x, int p_index_y) {
    int island_temp_list[TABLE_SIZE][2] = { 0 };
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    island_temp_list[0][0] = p_index_x;
    island_temp_list[0][1] = p_index_y;
    int island_temp_list_index = 1;
    int update_temp_list_index = 0;
    int temp_index = island_temp_list_index;
    while (update_temp_list_index != temp_index) {
        for (int i = update_temp_list_index; i < temp_index; i++) {
            for (int j = 0; j < 4; j++) {
                int x = island_temp_list[i][0] + dx[j];
                int y = island_temp_list[i][1] + dy[j];
                if (x < 0 || x >= row_size || y < 0 || y >= col_size || grid[x][y] != '1') {
                    continue;
                }
                grid[x][y] = '0';
                island_temp_list[island_temp_list_index][0] = x;
                island_temp_list[island_temp_list_index][1] = y;
                island_temp_list_index += 1;
            }
        }
        update_temp_list_index = temp_index;
        temp_index = island_temp_list_index;
    }
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