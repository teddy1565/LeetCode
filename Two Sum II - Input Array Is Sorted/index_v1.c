#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int answer[2] = { 0, 0 };
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* numbers, int numbersSize, int target, int* returnSize) {
    (*returnSize) = 2;
    for (int i = 0; i < numbersSize; i++) {
        int low = i + 1;
        int high = numbersSize - 1;
        int t = target - numbers[i];
        answer[0] = i;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (numbers[mid] > t) {
                high = mid - 1;
            } else {
                answer[1] = mid;
                low = mid + 1;
            }
        }
        if (numbers[answer[0]] + numbers[answer[1]] == target) {
            break;
        }
    }
    answer[0] += 1;
    answer[1] += 1;
    return answer;
}
