#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    // 1. 初始化資料結構
    int *in_degree = (int *) calloc(numCourses, sizeof(int));
    int **adj = (int **) malloc(numCourses * sizeof(int *));
    int *adj_size = (int *) calloc(numCourses, sizeof(int));
    
    // 預分配空間 (為了效能，實際開發建議用動態擴張)
    for (int i = 0; i < numCourses; i++) {
        adj[i] = (int *) malloc(numCourses * sizeof(int));
    }

    // 2. 建立圖 (A -> B 代表 A 是 B 的先修)
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        adj[prereq][adj_size[prereq]++] = course;
        in_degree[course]++;
    }

    // 3. 準備 Queue 與結果陣列
    int *ans = (int *) malloc(numCourses * sizeof(int));
    int *queue = (int *) malloc(numCourses * sizeof(int));
    int head = 0, tail = 0;

    // 將所有不需要先修的課放入 Queue
    for (int i = 0; i < numCourses; i++) {
        if (in_degree[i] == 0) {
            queue[tail++] = i;
        }
    }

    // 4. 開始拓撲排序 (Kahn's Algorithm)
    int count = 0;
    while (head < tail) {
        int curr = queue[head++];
        ans[count++] = curr;

        // 遍歷所有以 curr 為先修的課
        for (int i = 0; i < adj_size[curr]; i++) {
            int next_course = adj[curr][i];
            in_degree[next_course]--; // 滿足了一個先修條件
            if (in_degree[next_course] == 0) {
                queue[tail++] = next_course;
            }
        }
    }

    // 釋放記憶體
    for (int i = 0; i < numCourses; i++) free(adj[i]);
    free(adj); free(adj_size); free(in_degree); free(queue);

    // 5. 判斷是否有環 (是否所有課都修到了)
    if (count == numCourses) {
        *returnSize = numCourses;
        return ans;
    } else {
        *returnSize = 0;
        free(ans);
        return NULL;
    }
}