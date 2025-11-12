#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

#define ESC_MIN -1
#define ESC_MAX 1000000000

#define GRASS 0
#define FIRE 1
#define WALL 2
#define USER 3
#define ESC_DOOR 4

void show_canvas(int** grid_root, int row_size, int col_size) {
    printf("\n");
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            if (grid_root[i][j] == GRASS) {
                printf("* ");
            } else if (grid_root[i][j] == FIRE) {
                printf("F ");
            } else if (grid_root[i][j] == WALL) {
                printf("+ ");
            } else if (grid_root[i][j] == USER) {
                printf("U ");
            } else if (grid_root[i][j] == ESC_DOOR) {
                printf("E ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

bool escape_loop(int** grid_root, int row_size, int col_size, int delay_t) {
    int dx[4] = { 1, -1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    bool answer = false;

    int **grid = (int **) malloc(sizeof(int *) * row_size);
    for (int i = 0; i < row_size; i++) {
        grid[i] = (int *) malloc(sizeof(int) * col_size);
        memcpy(grid[i], grid_root[i], sizeof(int) * col_size);
    }

    int **fire_queue = (int **) malloc(sizeof(int *) * (row_size * col_size));
    int **user_queue = (int **) malloc(sizeof(int *) * (row_size * col_size));
    

    int fire_queue_index = 0;
    int user_queue_index = 0;

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
            } else if (grid[i][j] == USER) {
                user_queue[user_queue_index][0] = i;
                user_queue[user_queue_index][1] = j;
                user_queue_index++;
            }
        }
    }

    int offset_user_queue_index = 0;
    int safe_house_fire = 0;

    if (user_queue_index == 0) {
        answer = false;
        goto release_resource;
    } else if (fire_queue_index == 0) {
        delay_t = 0;
    }

    

    while (user_queue_index - offset_user_queue_index > 0) {

        // show_canvas(grid, row_size, col_size);

        int update_fire_queue_index = fire_queue_index;
        for (int i = 0; i < fire_queue_index; i++) {
            for (int j = 0; j < 4; j++) {
                int x = fire_queue[i][0] + dx[j];
                int y = fire_queue[i][1] + dy[j];
                if (
                    x >= row_size || x < 0 || y >= col_size || y < 0 ||
                    grid[x][y] == WALL || grid[x][y] == FIRE
                ) {
                    continue;
                } else if (grid[x][y] == ESC_DOOR) {
                    answer = false;
                    for (int j = 0; j < 4; j++) {
                        
                        int ux = x + dx[j];
                        int uy = y + dy[j];
                        if (
                            ux >= row_size || ux < 0 || uy >= col_size || uy < 0 ||
                            grid[ux][uy] != USER
                        ) {
                            continue;
                        }
                        answer = true;
                    }
                    goto release_resource;
                }
                grid[x][y] = FIRE;
                fire_queue[update_fire_queue_index][0] = x;
                fire_queue[update_fire_queue_index][1] = y;
                update_fire_queue_index++;
            }
        }
        
        if (fire_queue_index == update_fire_queue_index && fire_queue_index != 0) {
            answer = true;
            goto release_resource;
        }

        fire_queue_index = update_fire_queue_index;

        if (delay_t > 0) {
            delay_t -= 1;
            continue;
        }
        int update_user_queue_index = user_queue_index;
        for (int i = offset_user_queue_index; i < user_queue_index; i++) {
            // if (grid[user_queue[i][0]][user_queue[i][1]] == FIRE) {
            //     offset_user_queue_index++;
            //     continue;
            // }
            for (int j = 0; j < 4; j++) {
                int x = user_queue[i][0] + dx[j];
                int y = user_queue[i][1] + dy[j];
                if (
                    x >= row_size || x < 0 || y >= col_size || y < 0 ||
                    grid[x][y] == WALL || grid[x][y] == FIRE || grid[x][y] == USER
                ) {
                    continue;
                } else if (grid[x][y] == ESC_DOOR) {
                    answer = true;
                    goto release_resource;
                }

                grid[x][y] = USER;
                user_queue[update_user_queue_index][0] = x;
                user_queue[update_user_queue_index][1] = y;
                update_user_queue_index++;
            }
            offset_user_queue_index++;
        }

        if (user_queue_index == update_user_queue_index) {
            answer = false;
            goto release_resource;
        }
        user_queue_index = update_user_queue_index;
    }


    release_resource:
        // show_canvas(grid, row_size, col_size);
        for (int i = 0; i < row_size; i++) {
            free(grid[i]);
        }
        for (int i = 0; i < (row_size * col_size); i++) {
            free(fire_queue[i]);
            free(user_queue[i]);
        }

        free(grid);
        free(fire_queue);
        free(user_queue);

    return answer;

}

int maximumMinutes(int** grid, int gridSize, int* gridColSize) {
    if (gridSize > 0 && gridColSize[gridSize-1] > 0 && grid[0][0] == FIRE) {
        return -1;
    }
    
    int row_size = gridSize;
    int col_size = gridColSize[gridSize-1];
    grid[0][0] = USER;
    grid[row_size-1][col_size-1] = ESC_DOOR;

    int min_check = escape_loop(grid, row_size, col_size, 0);
    printf("min_check: %d\n", min_check);
    if (min_check == false) {
        return ESC_MIN;
    }

    
    int max_check = escape_loop(grid, row_size, col_size, ESC_MAX);
    printf("max_check: %d\n", max_check);
    if (max_check == true) {
        return ESC_MAX;
    }

    if (min_check == max_check) {
        return ESC_MAX;
    }


    int lo = 0;
    int hi = max_check == 0 ? 10000:20000;
    int old_mid = (hi + lo);
    while (lo < hi) {
        int mid = (hi + lo) / 2;
        if (mid == old_mid) {
            break;
        } else {
            old_mid = mid;
        }
        if (escape_loop(grid, row_size, col_size, mid) == false) {
            hi = mid;
        } else {
            lo = mid;
        }
        printf("%d %d\n", hi, lo);
    }

    return lo;
}

int main(void) {
    return 0;
}