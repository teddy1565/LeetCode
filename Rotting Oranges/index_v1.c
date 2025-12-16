#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define EMPTY 0
#define FRESH_ORANGE 1
#define ROTTEN_ORANGE 2

int orangesRotting(int** grid, int gridSize, int* gridColSize) {
    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    int row_size = gridSize;
    int col_size = gridColSize[0];
    int fresh_orange_size = 0;

    int rotten_orange_queue_index = 0;
    int fresh_orange_queue_index = 0;

    int **rotten_orange_queue = (int **) malloc(sizeof(int *) * (row_size * col_size));
    int **fresh_orange_queue = (int **) malloc(sizeof(int *) * (row_size * col_size));
    for (int i = 0; i < (row_size * col_size); i++) {
        rotten_orange_queue[i] = (int *) malloc(sizeof(int) * 2);
        fresh_orange_queue[i] = (int *) malloc(sizeof(int) * 2);
        memset(rotten_orange_queue[i], 0, sizeof(int) * 2);
        memset(fresh_orange_queue[i], 0, sizeof(int) * 2);
    }
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            if (grid[i][j] == FRESH_ORANGE) {
                fresh_orange_queue[fresh_orange_queue_index][0] = i;
                fresh_orange_queue[fresh_orange_queue_index][1] = j;
                fresh_orange_queue_index += 1;
                fresh_orange_size += 1;
            } else if (grid[i][j] == ROTTEN_ORANGE) {
                rotten_orange_queue[rotten_orange_queue_index][0] = i;
                rotten_orange_queue[rotten_orange_queue_index][1] = j;
                rotten_orange_queue_index += 1;
            }
        }
    }

    int minute = 0;
    while (fresh_orange_size > 0) {
        int update_rotten_orange_queue_index = rotten_orange_queue_index;
        for (int i = 0; i < rotten_orange_queue_index; i++) {
            for (int j = 0; j < 4; j++) {
                int x = rotten_orange_queue[i][0] + dx[j];
                int y = rotten_orange_queue[i][1] + dy[j];
                if (x < 0 || x >= row_size || y < 0 || y >= col_size || grid[x][y] == EMPTY || grid[x][y] == ROTTEN_ORANGE) {
                    continue;
                }
                grid[x][y] = ROTTEN_ORANGE;
                rotten_orange_queue[update_rotten_orange_queue_index][0] = x;
                rotten_orange_queue[update_rotten_orange_queue_index][1] = y;
                update_rotten_orange_queue_index += 1;
                fresh_orange_size -= 1;
            }
        }
        if (rotten_orange_queue_index == update_rotten_orange_queue_index) {
            break;
        }
        minute += 1;
        rotten_orange_queue_index = update_rotten_orange_queue_index;
    }

    if (fresh_orange_size != 0) {
        return -1;
    }

    return minute;
}
