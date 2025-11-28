#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define OFFSET 10001
#define HASH_MAP_SIZE 20005

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    (*returnSize) = 0;
    int *hash_map = (int *) malloc(sizeof(int) * HASH_MAP_SIZE);
    memset(hash_map, 0, sizeof(int) * HASH_MAP_SIZE);

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] < 0) {
            hash_map[(-nums[i])] += 1;
        } else {
            hash_map[nums[i] + OFFSET] += 1;
        }
    }

    for (int i = 0; i < HASH_MAP_SIZE && (*returnSize) < k; i++) {
        if (hash_map[i] != 0) {
            (*returnSize) += 1;
        }
    }

    int *answer = (int *) malloc(sizeof(int) * (*returnSize));
    memset(answer, 0, sizeof(int) * (*returnSize));
    

    int interrpute_index = 0;
    for (int interrpute_index = 0, answer_index = 0; interrpute_index < numsSize && answer_index < (*returnSize); interrpute_index++) {
        int k = 0;
        if (nums[interrpute_index] < 0) {
            k = hash_map[-nums[interrpute_index]];
        } else {
            k = hash_map[nums[interrpute_index] + OFFSET];
        }

        int last_small_index = answer[(*returnSize) - 1];

        if (k >= answer[last_small_index]) {
            int prev_last = answer[(*returnSize) - 1];
            
        }
    }

    int temp = nums[0];
    int answer_size = 1;

    for (int i = 0; i < numsSize; i++) {
        int k = 0;
        if (nums[i] < 0) {
            k = hash_map[-nums[i]];
        } else {
            k = hash_map[nums[i] + OFFSET];
        }

        int x = 0;
        if (temp < 0) {
            x = hash_map[-temp];
        } else {
            x = hash_map[temp + OFFSET];
        }

        if (k < x) {
            continue;
        }

        int find_repeat = 0;
        for (int j = 0; j < answer_size; j++) {
            if (answer[j] == nums[i]) {
                find_repeat = 1;
                break;
            }
        }

        printf("temp: %d | nums: %d\n", temp, nums[i]);
        if (find_repeat) {
            continue;
        }

        
        // printf("temp: %d | nums: %d\n", temp, nums[i]);

        // int changes = 0; 
        
        for (int j = 0, inner_temp = temp, s = nums[i]; j < (*returnSize); j++) {
            
            int c = 0;
            if (answer[j] < 0) {
                c = hash_map[-answer[j]];
            } else {
                c = hash_map[answer[j] + OFFSET];
            }
            if (k > c) {
                printf("answer[%d]: %d\n", j, answer[j]);
                temp = answer[j];
                answer[j] = s;
                int g = 0;
                int h = 0;
                if (temp < 0) {
                    g = hash_map[-temp];
                } else {
                    g = hash_map[temp + OFFSET];
                }

                if (inner_temp < 0) {
                    h = hash_map[-inner_temp];
                } else {
                    h = hash_map[inner_temp + OFFSET];
                }

                if (g < h) {
                    s = temp;
                } else {
                    s = inner_temp;
                }
                inner_temp = temp;
            }
        }
        // printf("changes: %d\n", changes);
        // printf("index: %d | temp: %d\n", i, temp);
    }

    for (int i = 0; i < HASH_MAP_SIZE; i++) {
        if (hash_map[i] != 0) {
            printf("h: %d %d\n", i, hash_map[i]);
        }
    }

    for (int i = 0; i < (*returnSize); i++) {
        printf("%d ", answer[i]);
    }
    printf("\n");

    return answer;
}