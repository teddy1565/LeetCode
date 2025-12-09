#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// dp 陣列：用來記錄 LIS (最長遞增子序列) 的狀態
// dp[i] 代表「長度為 i+1 的遞增子序列中，結尾數值最小的那個數」
int dp[100000];

// 比較函式：這是本題最核心的邏輯
int compare(const void *a, const void *b) {
    int **nodeA = (int **)a;
    int **nodeB = (int **)b;
    
    // 1. 先比較寬度 (Width)
    // 寬度較小的排前面 (升序)
    int w = ((*nodeA)[0] - (*nodeB)[0]);
    
    // 2. 如果寬度一樣，則比較高度 (Height)
    // 關鍵！高度較大的排前面 (降序)
    // 原因：若寬度相同 (e.g., [3,3], [3,4])，我們不能讓它們形成遞增序列。
    // 透過降序排列變成 [3,4], [3,3]，在找高度的 LIS 時，3 不大於 4，
    // 就不會誤判這兩個信封可以互相套入。
    int h = ((*nodeB)[1] - (*nodeA)[1]);

    if (w == 0) return h;
    return w;
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize) {
    // 初始化 dp 陣列
    memset(dp, 0, sizeof(int) * envelopesSize);
    
    // 步驟一：排序
    // 複雜度 O(N log N)
    qsort(envelopes, envelopesSize, sizeof(int) * 2, compare);

    // 步驟二：在高度陣列中尋找 LIS (最長遞增子序列)
    // dp_size 代表目前找到的最長子序列長度
    int dp_size = 0;
    
    for (int i = 0; i < envelopesSize; i++) {
        // 我們只需要關注高度
        int target = envelopes[i][1];
        
        // 使用 Binary Search (二分搜尋) 在 dp 陣列中找位置
        // 目標：找到第一個 "大於或等於" target 的位置 (Lower Bound)
        int left = 0, right = dp_size;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (dp[mid] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        
        // 判斷搜尋結果
        if (right >= dp_size) {
            // 如果沒找到比 target 大的數 (代表 target 比 dp 裡所有數都大)
            // 它可以接在目前最長序列的後面，長度 +1
            dp[dp_size++] = target;
        } else {
            // 如果找到了 (dp[right] >= target)
            // 我們用更小的 target 替換掉原本的 dp[right]
            // 這讓該長度的序列結尾更小，未來更有機會接上新數字 (貪心策略)
            dp[right] = target;
        }
    }
    
    return dp_size;
}