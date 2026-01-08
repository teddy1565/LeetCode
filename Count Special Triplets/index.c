#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// A special triplet is defined as a triplet of indices (i, j, k) such that:

// 0 <= i < j < k < n, where n = nums.length
// nums[i] == nums[j] * 2
// nums[k] == nums[j] * 2
// Return the total number of special triplets in the array.

// Since the answer may be large, return it modulo 109 + 7.


// Constraints:

// 3 <= n == nums.length <= 105
// 0 <= nums[i] <= 105

/**
 * @brief 計算滿足特定倍數關係的三元組數量
 * * 尋找三元組 (p, q, r) 滿足下標 p < q < r，且數值滿足：
 * nums[p] == nums[q] * 2 且 nums[r] == nums[q] * 2
 * * @algorithm 核心思路：枚舉中間元素 (Center Pivot)
 * 1. 預處理：先將所有數字計入 right_map，代表初始狀態下所有數字都在「右側」。
 * 2. 遍歷陣列：將當前遍歷到的元素視為三元組的中間元素 (Center, nums[q])。
 * - 狀態轉移：將當前元素從 right_map 移除（它不再屬於右側）。
 * - 計算貢獻：若左側 (left_map) 和右側 (right_map) 都有目標值 (nums[q] * 2)，
 * 則當前中間元素能組成的三元組數量為：(左側目標數量 * 右側目標數量)。
 * - 狀態更新：計算完畢後，將當前元素加入 left_map（它變成了下一個元素的左側）。
 * * @note 時間複雜度: O(N), 空間複雜度: O(K) 其中 K 為數值範圍
 * * @param nums 輸入的整數陣列
 * @param numsSize 陣列長度
 * @return int 滿足條件的三元組總數 (結果對 10^9 + 7 取模)
 */

/**
 * @brief 
 * 由於i 在左邊 j 在中間 k在右邊
 * 又需要滿足 i == j*2 && k == j * 2
 * 
 * 因此使用兩個hash map維持狀態
 * 當right的hash map經歷過一個較大的數字時，但left還沒經歷過，那麼不可能滿足
 * 
 * 可以被計算的組合可能性，則為兩邊的乘積
 * 
 * @param nums 
 * @param numsSize 
 * @return int 
 */
int specialTriplets(int* nums, int numsSize) {
    int right_map[100001] = { 0 };
    int left_map[100001] = { 0 };
    int answer = 0;
    const int MOD_V = 1000000007;
    for (int i = 0; i < numsSize; i++) {
        right_map[nums[i]] += 1;
    }
    for (int i = 0; i < numsSize; i++) {
        right_map[nums[i]] -= 1;
        
        if (nums[i] <= 50000) {
            int target_value = nums[i] * 2;
            int left_value = left_map[target_value];
            int right_value = right_map[target_value];
            answer = ((answer + ((long int)left_value * (long int)right_value) % MOD_V) % MOD_V);
        }
        
        left_map[nums[i]] += 1;
    }

    return answer;
}
