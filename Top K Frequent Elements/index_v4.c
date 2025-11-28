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
    

    int temp = answer[0];
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

        if (find_repeat) {
            printf("I: %d\n", i);
            continue;
        }

        int size_grow = 0;

        for (int j = 0, m = nums[i]; j < answer_size; j++) {
            int c = 0;
            if (answer[j] < 0) {
                c = hash_map[-answer[j]];
            } else {
                c = hash_map[answer[j] + OFFSET];
            }
            if (m < 0) {
                k = hash_map[-m];
            } else {
                k = hash_map[m + OFFSET];
            }

            if (k > c) {
                size_grow = 1;
                int d = 0;
                int answer_temp = answer[j];
                answer[j] = m;
                
                if (answer_temp < 0) {
                    d = hash_map[-answer_temp];
                } else {
                    d = hash_map[answer_temp + OFFSET];
                }
                if (d > x) {
                    m = answer_temp;
                    temp = answer_temp;
                } else {
                    m = temp;
                    temp = answer_temp;
                }
            }
        }

        if (size_grow == 1) {
            answer_size += 1;
            if (answer_size > (*returnSize)) {
                answer_size = (*returnSize);
            }
        }

        for (int i = 0; i < (*returnSize); i++) {
            printf("%d ", answer[i]);
        }
        printf("\n");
        
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