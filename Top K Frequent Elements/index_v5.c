#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

#define OFFSET 10001
#define HASH_MAP_SIZE 20005


int hash_map_value(int *hash_map, int key) {
    if (key < 0) return hash_map[-key];
    else return hash_map[key + OFFSET];
}
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
    for (int i = 0; i < (*returnSize); i++) {
        answer[i] = INT_MAX;
    }

    int temp = answer[0];
    int answer_size = 1;

    for (int i = 0; i < numsSize; i++) {
        int k = hash_map_value(hash_map, nums[i]);

        int x = 0;
        if (temp != INT_MAX) {
            x = hash_map_value(hash_map, temp);
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
            continue;
        }

        int size_grow = 0;

        for (int j = 0, m = nums[i]; j < answer_size; j++) {
            int c = 0;
            if (answer[j] != INT_MAX) {
                c = hash_map_value(hash_map, answer[j]);
            }
            k = hash_map_value(hash_map, m);

            if (k > c) {
                size_grow = 1;
                int d = 0;
                int answer_temp = answer[j];
                answer[j] = m;
                if (answer_temp != INT_MAX) {
                    d = hash_map_value(hash_map, answer_temp);
                }
                if (d >= x) {
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

        
    }

    free(hash_map);

    return answer;
}