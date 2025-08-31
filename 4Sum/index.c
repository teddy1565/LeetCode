#include "index.h"

#define DEBUG

static void print_test_case(int *test_case, int numsSize) {
    printf("\n====================\n");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", test_case[i]);
    }
    printf("\n-----------------------------\n");
}

struct ANSWER {
    struct ANSWER *prev;
    struct ANSWER *next;
    int *p;
} ANSWER;

int compare_cb(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes) {
    (*returnSize) = 0;
    free((*returnColumnSizes));

    qsort(nums, numsSize, sizeof(int), &compare_cb);
    
    int **answer = (int **) malloc(sizeof(int *) * numsSize * 16);

    (*returnColumnSizes) = (int *) malloc(sizeof(int) * numsSize * 16);
    for (int i = 0; i < numsSize * 16; i++) {
        (*returnColumnSizes)[i] = 4;
    }

    // struct ANSWER *p = (struct ANSWER *) malloc(sizeof(struct ANSWER));
    // p->next = NULL;
    // p->prev = NULL;
    // p->p = NULL;

    for (int i = 0; i < numsSize-3; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        for (int j = i + 1; j < numsSize-2; j++) {
            if (j > (i + 1) && nums[j] == nums[j - 1]) {
                continue;
            }
            int x = target - nums[i];
            int y = target - nums[j];
            if (abs(x) > 1000000000 && abs(y) > 1000000000) {
                continue;
            }
            int n =  target - (nums[i] + nums[j]);
            int left = j + 1;
            int right = numsSize - 1;
            while (left < right) {
                if (nums[left] + nums[right] > n) {
                    right--;
                } else if (nums[left] + nums[right] < n) {
                    left++;
                } else {
                    answer[(*returnSize)] = (int *) malloc(sizeof(int) * 4);
                    answer[(*returnSize)][0] = nums[i];
                    answer[(*returnSize)][1] = nums[j];
                    answer[(*returnSize)][2] = nums[left];
                    answer[(*returnSize)][3] = nums[right];
                    (*returnSize) = (*returnSize) + 1;
                    left++;
                    right--;
                    while (left < right && nums[left] == nums[left - 1]) {
                        left++;
                    }
                    while (right > left && nums[right] == nums[right + 1]) {
                        right--;
                    }
                }
            }

        }
    }

    
    return answer;
}

int main(void) {
    int test_case_01[6] = { 1, 0, -1, 0, -2, 2 };
    int test_case_02[5] = { 2, 2, 2, 2, 2 };
    int test_case_03[4] = { 0, 0, 0, 0 };
    int test_case_04[7] = { -2, -1, -1, 1, 1, 2, 2 };
    int test_case_05[6] = { -1, 0, 1, 2, -1, -4 };
    int test_case_06[9] = { -3, -4, -5, 0, -5, -2, 5, 2, -3 };
    int test_case_07[4] = { 1000000000, 1000000000, 1000000000, 1000000000 };

    int returnSize = 0;
    int *p = NULL;

    fourSum(test_case_01, 6, 0, &returnSize, &p);
    fourSum(test_case_02, 5, 8, &returnSize, &p);
    fourSum(test_case_03, 4, 1, &returnSize, &p);
    fourSum(test_case_04, 7, 0, &returnSize, &p);
    fourSum(test_case_05, 6, -1, &returnSize, &p);
    fourSum(test_case_06, 9, 3, &returnSize, &p);
    fourSum(test_case_07, 4, 0, &returnSize, &p);
    return 0;
}