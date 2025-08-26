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

    int **p = NULL;

    int base_index = -1;
    for (int i = 0; i < numsSize - 2; i++) {
        if (base_index != -1) {
            if (nums[base_index] == nums[i]) {
                base_index++;
                continue;
            } else {
                base_index = i;
            }
        } else if (base_index == -1) {
            base_index = i;
        }

        
        for (int j = i + 1; j < numsSize - 1; j++) {
            for (int k = j + 1; k < numsSize; k++) {
                if ((nums[j] + nums[k] == -nums[i]) || (nums[i] + nums[j] == -nums[k]) || (nums[i] + nums[k] == -nums[j])) {
                    (*returnSize) = (*returnSize) + 1;

                    int **temp_p = realloc(p, sizeof(int *) * (*returnSize));

                    if (temp_p != NULL) {
                        p = temp_p;
                        temp_p = NULL;
                    }
                    temp_p = realloc(returnColumnSizes, sizeof(int *) * (*returnSize));
                    if (temp_p != NULL) {
                        returnColumnSizes = temp_p;
                        temp_p = NULL;
                    }

                    int p_index = (*returnSize) - 1;
                    returnColumnSizes[p_index] = malloc(sizeof(int));
                    returnColumnSizes[p_index][0] = 3;

                    p[p_index] = (int *) malloc(sizeof(int) * 3);
                    p[p_index][0] = nums[i];
                    p[p_index][1] = nums[j];
                    p[p_index][2] = nums[k];
                }
            }
        }
    }

    return p;
}

int main(void) {
    

    // qsort(test_case_01, 6, sizeof(int), &compare_cb);
    // printf_nums(test_case_01, 6);


    // qsort(test_case_02, 3, sizeof(int), &compare_cb);
    // printf_nums(test_case_02, 3);

    // qsort(test_case_03, 3, sizeof(int), &compare_cb);
    // printf_nums(test_case_03, 3);

    int returnSize = 0;
    int **returnColumnSizes = NULL;
    int **p = NULL;

    p = threeSum(test_case_01, 6, &returnSize, returnColumnSizes);
    printf("return_size: %d\n", returnSize);
    
    for (int i = 0; i < returnSize; i++) {
        printf("[%d]: %d | %d | %d \n", (returnColumnSizes[i][0]), p[i][0], p[i][1], p[i][2]);
    }

    returnSize = 0;

    return 0;

    threeSum(test_case_02, 3, &returnSize, returnColumnSizes);
    printf("return_size: %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("[%d]: %d | %d | %d \n", (returnColumnSizes[i][0]), p[i][0], p[i][1], p[i][2]);
    }
    returnSize = 0;

    threeSum(test_case_03, 3, &returnSize, returnColumnSizes);
    printf("return_size: %d\n", returnSize);
    for (int i = 0; i < returnSize; i++) {
        printf("[%d]: %d | %d | %d \n", (returnColumnSizes[i][0]), p[i][0], p[i][1], p[i][2]);
    }
    returnSize = 0;
    
    return 0;
}