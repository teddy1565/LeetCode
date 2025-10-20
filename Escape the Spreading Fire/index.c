#include "index.h"

int maximumMinutes(int** grid, int gridSize, int* gridColSize) {
    if (gridSize > 0 && gridColSize[gridSize-1] > 0 && grid[0][0] == FIRE) {
        return -1;
    }

    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };

    int row_size = gridSize;
    int col_size = gridColSize[gridSize-1];

    int **fire_queue = (int **) malloc(sizeof(int *) * (row_size * col_size));
    int **user_queue = (int **) malloc(sizeof(int *) * (row_size * col_size));

    int fire_queue_index = 0;
    int user_queue_index = 1;

    for (int i = 0; i < (row_size * col_size); i++) {
        fire_queue[i] = (int *) malloc(sizeof(int) * 2);
        user_queue[i] = (int *) malloc(sizeof(int) * 2);
        memset(fire_queue[i], 0, sizeof(int) * 2);
        memset(user_queue[i], 0, sizeof(int) * 2);
    }

    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            if (grid[i][j] == FIRE) {
                fire_queue[fire_queue_index][0] = i;
                fire_queue[fire_queue_index][1] = j;
                fire_queue_index++;
            }
        }
    }

    int offset_user_queue_index = 0;

    while (user_queue_index - offset_user_queue_index > 0) {

        for (int i = 0; i < row_size; i++) {
            for (int j = 0; j < col_size; j++) {
                printf("%d ", grid[i][j]);
            }
            printf("\n");
        }
        printf("\n\n");

        // for (int i = 0; i < (row_size * col_size); i++) {
        //     printf("%d %d\n", user_queue[i][0], user_queue[i][1]);
        // }

        int update_fire_queue_index = fire_queue_index;
        for (int i = 0; i < fire_queue_index; i++) {
            for (int j = 0; j < 4; j++) {
                int x = fire_queue[i][0] + dx[j];
                int y = fire_queue[i][1] + dy[j];
                if (
                    x >= row_size || x < 0 || y >= col_size || y < 0 ||
                    grid[x][y] == WALL || grid[x][y] == FIRE
                    ){
                        continue;
                }
                grid[x][y] = FIRE;
                fire_queue[update_fire_queue_index][0] = x;
                fire_queue[update_fire_queue_index][1] = y;
                update_fire_queue_index++;
            }
        }
        fire_queue_index = update_fire_queue_index;

        int update_user_queue_index = user_queue_index;
        for (int i = offset_user_queue_index; i < user_queue_index; i++) {
            int neer_has_fire = 0;
            for (int j = 0; j < 4; j++) {
                int x = user_queue[i][0] + dx[j];
                int y = user_queue[i][1] + dy[j];
                if (x >= row_size || x < 0 || y >= col_size || y < 0 ||
                    grid[x][y] == WALL) {
                    continue;
                } else if (grid[x][y] == FIRE) {
                    neer_has_fire = 1;
                    break;
                }
                for (int k = 0; k < 4; k++) {
                    int nx = x + dx[k];
                    int ny = y + dy[k];
                    if (nx >= row_size || nx < 0 || ny >= col_size || ny < 0 || grid[nx][ny] == WALL) {
                        continue;
                    } else if (grid[nx][ny] == FIRE) {
                        user_queue[update_user_queue_index][0] = x;
                        user_queue[update_user_queue_index][1] = y;
                        update_user_queue_index++;
                        offset_user_queue_index++;
                        grid[x][y] = 3;
                        break;
                    }
                }
            }

            if (neer_has_fire == 1) {
                for (int j = 0; j < 4; j++) {
                    int x = user_queue[i][0] + dx[j];
                    int y = user_queue[i][1] + dy[j];
                    if (x >= row_size || x < 0 || y >= col_size || y < 0 ||
                        grid[x][y] == WALL || grid[x][y] == FIRE) {
                        continue;
                    }
                    user_queue[update_user_queue_index][0] = x;
                    user_queue[update_user_queue_index][1] = y;
                    update_user_queue_index++;
                    offset_user_queue_index++;
                    grid[x][y] = 3;
                }
            }
        }
        user_queue_index = update_user_queue_index;
    }
    return 0;
}

int main(void) {
    return 0;
}