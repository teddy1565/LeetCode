#include "index.h"

static int compare_cb(const void *a, const void *b) {
    if (*(int *)a < *(int *)b) {
        return -1;
    } else if (*(int *)a == *(int *)b) {
        return 0;
    } else {
        return 1;
    }
}

static void printf_nums(int *nums, int numsSize) {
    for (int i = 0; i < numsSize;) {
        printf("%d", nums[i]);
        i++;
        if (i < numsSize) {
            printf(", ");
        } else {
            printf("\n");
        }
    }
}

/**
 * @brief
 * 
 * 首先觀察題目發現有幾個特點
 * 1. 不要重複的匹配組合
 * 2. 與TwoSum的差別在於，他不要求回傳索引位置，因此可以進行排序
 * 
 * @param nums 
 * @param numsSize 
 * @param returnSize 
 * @param returnColumnSizes 
 * @return int** 
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), &compare_cb);

    int mem_scale_x = 1;

    int **p = (int **) malloc(sizeof(int *) * 50 * (mem_scale_x++));
    int *skips = (int *) malloc(sizeof(int) * numsSize);
    int skips_index = 0;
    
    int a = 0, b = 1, k = 2;
    printf_nums(nums, numsSize);
    printf("\n");

    for (; k < numsSize; k++) {
        for (int m = 0; m < skips_index; m++) {
            if (skips[m] == k) {
                goto k_loop;
            }
        }

        if (nums[a] + nums[b] + nums[k] == 0) {
            skips[skips_index++] = k;
            (*returnSize) = (*returnSize) + 1;
            printf("%d, %d, %d | %d %d %d\n", a, b, k, nums[a], nums[b], nums[k]);
        }

        k_loop:
            continue;
    }

    k = 2;

    for (; b < (numsSize - 1); b++) {
        for (int m = 0; m < skips_index; m++) {
            if (skips[m] == b) {
                goto b_loop;
            }
        }

        if (nums[a] + nums[b] + nums[k] == 0) {
            (*returnSize) = (*returnSize) + 1;
            skips[skips_index++] = b;
            printf("%d, %d, %d | %d %d %d\n", a, b, k, nums[a], nums[b], nums[k]);
        }

        b_loop:
            continue;
    }

    b = 1;

    for (; a < (numsSize - 1); a++) {
        for (int m = 0; m < skips_index; m++) {
            if (skips[m] == a) {
                goto a_loop;
            }
        }

        if (nums[a] + nums[b] + nums[k] == 0) {
            (*returnSize) = (*returnSize) + 1;
            skips[skips_index++] = a;
            printf("%d, %d, %d | %d %d %d\n", a, b, k, nums[a], nums[b], nums[k]);
        }

        a_loop:
            continue;
    }



    (*returnColumnSizes) = (int *) malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < (*returnSize); i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return p;
}


int main(void) {

    int returnSize = 0;
    int *returnColumnSizes = NULL;
    int **p = NULL;

    p = threeSum(test_case_01, 6, &returnSize, &returnColumnSizes);
    printf("return_size: %d\n", returnSize);
    

    returnSize = 0;

    threeSum(test_case_02, 3, &returnSize, &returnColumnSizes);
    printf("return_size: %d\n", returnSize);
    returnSize = 0;

    threeSum(test_case_03, 3, &returnSize, &returnColumnSizes);
    printf("return_size: %d\n", returnSize);
    returnSize = 0;
    
    return 0;
}