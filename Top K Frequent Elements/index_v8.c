#include <stdlib.h>
#include <string.h>



struct Node {
    int num;
    int count;
} Node;

int compare(const void *a, const void *b) {
    struct Node *node_a = (struct Node *) a;
    struct Node *node_b = (struct Node *) b;
    return node_b->count - node_a->count;
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    int map[20001] = { 0 };
    int offset = 10000;
    
    for (int i = 0; i < numsSize; i++) {
        map[nums[i] + offset] += 1;
    }

    struct Node *nodes = (struct Node *) malloc(sizeof(struct Node) * numsSize);
    int unique_count = 0;
    for (int i = 0; i <= 20000; i++) {
        if (map[i] > 0) {
            nodes[unique_count].num = i - offset;
            nodes[unique_count].count = map[i];
            unique_count += 1;
        }
    }

    qsort(nodes, unique_count, sizeof(struct Node), compare);

    (*returnSize) = k;
    int *result = (int *) malloc(sizeof(int) * k);
    
    for (int i = 0; i < k; i++) {
        result[i] = nodes[i].num;
    }

    free(nodes);

    return result;

}