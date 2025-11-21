#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


// $$\text{Sum}(\text{Sub}_{i, j}) = \text{PrefixSum}[j] - \text{PrefixSum}[i-1]$
struct MapItem {
    char key[20];
    int val;
} MapItem;

struct Map {
    int* (*get)(struct Map *self, int key);
    char* (*set)(struct Map *self, int key, int value);
    struct MapItem *map_list;
} Map;

int* map_get(struct Map *map, int key) {
    return NULL;
}

char* map_set(struct Map *map, int key, int value) {
    return NULL;
}

struct Map* create_map(int map_size) {
    struct Map* map = (struct Map *) malloc(sizeof(struct Map));
    map->map_list = (struct MapItem *) malloc(sizeof(struct MapItem) * map_size);
    map->get = map_get;
    map->set = map_set;
    return map;
}

void free_map(struct Map* map) {
    free(map->map_list);
    free(map);
}


int subarraySum(int* nums, int numsSize, int k) {
    if (numsSize == 0) {
        return 0;
    } else if (numsSize == 1) {
        if (k == nums[0]) {
            return 1;
        }
        return 0;
    }
    int n = 0;
    for (int i = 1; i < numsSize; i++) {
        nums[i] += nums[i - 1];
    }

    for (int loop_index = 0; loop_index < numsSize; loop_index++) {
        int m = nums[loop_index] - k;
        if (m == 0) n++;
        for (int i = loop_index-1; i >= 0; i--) {
            if (nums[i] == m) n++;
        }
    }

    return n;
}

int main(void) {
    return 0;
}