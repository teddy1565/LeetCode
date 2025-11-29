#include <stdlib.h>
#include <string.h>

// 定義結構體來儲存數字及其頻率
typedef struct {
    int num;
    int count;
} Node;

// 比較函式，用於 qsort (依照頻率由大到小排序)
int compare(const void *a, const void *b) {
    Node *nodeA = (Node *)a;
    Node *nodeB = (Node *)b;
    return nodeB->count - nodeA->count; // 降冪排序
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {
    // 1. 初始化計數陣列 (假設數值範圍在 -10000 到 10000 之間)
    // 使用位移量 10000，讓 index 0 代表 -10000
    int map[20001] = {0}; 
    int offset = 10000;

    // 2. 統計頻率
    for (int i = 0; i < numsSize; i++) {
        map[nums[i] + offset]++;
    }

    // 3. 將有出現的數字轉存到 Node 陣列中
    // 最多只會有 numsSize 個不重複數字，或者是 map 的大小
    Node *nodes = (Node *)malloc(sizeof(Node) * numsSize);
    int uniqueCount = 0;

    for (int i = 0; i <= 20000; i++) {
        if (map[i] > 0) {
            nodes[uniqueCount].num = i - offset; // 還原數值
            nodes[uniqueCount].count = map[i];
            uniqueCount++;
        }
    }

    // 4. 排序 (依照頻率)
    qsort(nodes, uniqueCount, sizeof(Node), compare);

    // 5. 取出前 k 個
    *returnSize = k;
    int *result = (int *)malloc(sizeof(int) * k);
    
    for (int i = 0; i < k; i++) {
        result[i] = nodes[i].num;
    }

    // 6. 釋放暫存記憶體
    free(nodes);

    return result;
}