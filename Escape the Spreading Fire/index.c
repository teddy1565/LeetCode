#include "index.h"

int maximumMinutes(int** grid, int gridSize, int* gridColSize) {
    if (gridSize > 0 && gridColSize[gridSize-1] > 0 && grid[0][0] == FIRE) {
        return -1;
    }

    int dx[4] = { 0, 0, 1, -1 };
    int dy[4] = { 1, -1, 0, 0 };
    grid[0][0] = USER;

    int row_size = gridSize;
    int col_size = gridColSize[gridSize-1];
    grid[row_size-1][col_size-1] = ESC_DOOR;

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
    int fire_timer = 0;
    int user_timer = 0;
    int fire_timer_stop_signal = 0;
    int esc_success_signal = 0;
    int user_timer_stop_signal = 0;

    while (user_queue_index - offset_user_queue_index > 0) {

        // for (int i = 0; i < row_size; i++) {
        //     for (int j = 0; j < col_size; j++) {
        //         printf("%d ", grid[i][j]);
        //     }
        //     printf("\n");
        // }
        // printf("\n\n");

        int update_fire_queue_index = fire_queue_index;
        for (int i = 0; i < fire_queue_index; i++) {
            for (int j = 0; j < 4; j++) {
                int x = fire_queue[i][0] + dx[j];
                int y = fire_queue[i][1] + dy[j];
                if (
                    x >= row_size || x < 0 || y >= col_size || y < 0 ||
                    grid[x][y] == WALL || grid[x][y] == FIRE || grid[x][y] == ESC_DOOR
                    ){
                        continue;
                } else if (grid[x][y] == USER) {
                    fire_timer_stop_signal = 1;
                }
                grid[x][y] = FIRE;
                fire_queue[update_fire_queue_index][0] = x;
                fire_queue[update_fire_queue_index][1] = y;
                update_fire_queue_index++;
            }
        }
        if (fire_timer_stop_signal == 0) {
            fire_timer += 1;
        }
        fire_queue_index = update_fire_queue_index;

        int update_user_queue_index = user_queue_index;
        for (int i = offset_user_queue_index; i < user_queue_index; i++) {
            for (int j = 0; j < 4; j++) {
                int x = user_queue[i][0] + dx[j];
                int y = user_queue[i][1] + dy[j];
                if (x >= row_size || x < 0 || y >= col_size || y < 0 ||
                    grid[x][y] == WALL || grid[x][y] == FIRE || grid[x][y] == USER) {
                    continue;
                } else if (grid[x][y] == ESC_DOOR) {
                    esc_success_signal = 1;
                    user_timer++;
                    user_timer_stop_signal = 1;
                }
                
                grid[x][y] = 3;
                user_queue[update_user_queue_index][0] = x;
                user_queue[update_user_queue_index][1] = y;
                update_user_queue_index++;
            }
            offset_user_queue_index++;
        }
        if (user_timer_stop_signal == 0) {
            user_timer++;
        }
        user_queue_index = update_user_queue_index;
    }

    printf("fire_timer: %d\n", fire_timer);
    printf("fire_timer_sig: %d\n", fire_timer_stop_signal);
    printf("esc_success_sig: %d\n", esc_success_signal);
    printf("user_timer: %d\n", user_timer);

    if (fire_timer == 0) {
        return ESC_MAX;
    } else if (fire_timer == 1 && esc_success_signal == 0) {
        return ESC_MIN;
    } else if (esc_success_signal == 1 && fire_timer_stop_signal == 0 && user_timer == fire_timer-1) {
        return ESC_MAX;
    } else if (esc_success_signal == 1 && fire_timer_stop_signal == 1 && user_timer == fire_timer) {
        return 0;
    } else if (esc_success_signal == 0) {
        return ESC_MIN;
    }

    if (fire_timer_stop_signal == 1) {
        return fire_timer;
    }
    
    return user_timer - 1;
}

int main(void) {
    return 0;
}