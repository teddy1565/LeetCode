#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define HASH_SIZE 20011

struct entry {
    uint8_t key[26];
    uint8_t used;
};

static inline uint32_t hash32(uint8_t key[26]) {
    uint32_t h = 2166136261u;
    for (int i = 0; i < 26; i++) {
        h = h ^ key[i];
        h = h * 16777619u;
    }

    return h;
}

struct workspace {
    struct entry table[HASH_SIZE];
    int slot_to_group[HASH_SIZE];
};

static struct workspace ws;

char ***groupAnagrams(char **strs, int strs_size, int *out_size, int **out_group_sizes) {
    ws = (struct workspace) {.table = {}, .slot_to_group = {}};
    struct entry *table = ws.table;
    int *slot_to_group = ws.slot_to_group;
    int cap = 8;
    int num_groups = 0;
    char ***res = calloc(cap, sizeof(char **));
    int *group_sizes = malloc(cap * 2 * sizeof(int));
    int *group_caps = group_sizes + cap;
    for (int i = 0; i < strs_size; i++) {
        uint8_t key[26] = {};
        for (const unsigned char *p = (const unsigned char *) strs[i]; *p; p++) {
            key[*p - 'a']++;
        }
        uint32_t h = hash32(key) % HASH_SIZE;
        while (table[h].used && memcmp(table[h].key, key, 26) != 0) {
            h = (h + 1) % HASH_SIZE;
        }
        if (!table[h].used) {
            memcpy(table[h].key, key, 26);
            table[h].used = 1;
            slot_to_group[h] = num_groups;
            if (num_groups == cap) {
                cap = cap << 1;
                res = realloc(res, cap * sizeof(char **));
                group_sizes = realloc(group_sizes, cap * 2 * sizeof(int));
                group_caps = group_sizes + cap;
            }
            res[num_groups] = malloc(sizeof(char *) * 4);
            group_sizes[num_groups] = 0;
            group_caps[num_groups] = 4;
            num_groups += 1;
        }
        const int g = slot_to_group[h];

        if (group_sizes[g] == group_caps[g]) {
            group_caps[g] = group_caps[g] << 1;
            res[g] = realloc(res[g], group_caps[g] * sizeof(char *));
        }

        res[g][group_sizes[g]++] = strs[i];
    }
    *out_size = num_groups;
    *out_group_sizes = realloc(group_sizes, num_groups * sizeof(int));
    res = realloc(res, num_groups * sizeof(char **));
    return res;
}