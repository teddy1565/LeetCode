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

static void printf_answer(int **nums, int rows) {
    printf("\n");
    for (int i = 0; i < rows; i++) {
        int *p = nums[i];
        printf("%d %d %d\n", p[0], p[1], p[2]);

    }

    printf("=============\n\n");
}

#define MEM_BASE_X 10

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
    *returnSize = 0;
    free(*returnColumnSizes);


    qsort(nums, numsSize, sizeof(int), &compare_cb);
    // printf_nums(nums, numsSize);

    int mem_scale_x = 1;
    int p_row_index = 0;
    int **p = (int **) malloc(sizeof(int *) * MEM_BASE_X * (mem_scale_x));
    for (int i = 0; i < (MEM_BASE_X * mem_scale_x); i++) {
        p[i] = (int *) malloc(sizeof(int) * 3);
    }
    
    for (int i = 0; i < numsSize - 2; i++) {
        for (int left = i + 1, right = numsSize - 1; (left <= numsSize - 2) && (right >= i + 2) && left != (right + 1) && left != right;) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                (*returnSize) = (*returnSize) + 1;
                
                // printf("%d %d %d | %d %d %d\n", i, left, right, nums[i], nums[left], nums[right]);
                p[p_row_index][0] = nums[i];
                p[p_row_index][1] = nums[left];
                p[p_row_index][2] = nums[right];
                p_row_index++;
                
                if((*returnSize) == (MEM_BASE_X * mem_scale_x)) {
                    int **temp_p = realloc(p, sizeof(int *) * MEM_BASE_X * (mem_scale_x + 1));
                    if (temp_p != NULL) {
                        p = temp_p;
                        temp_p = NULL;
                        for (int p_i = (MEM_BASE_X * mem_scale_x); p_i < (MEM_BASE_X * (mem_scale_x + 1)); p_i++) {
                            p[p_i] = (int *) malloc(sizeof(int) * 3);
                        }
                        mem_scale_x++;
                    }
                }
                
                left_plus_check:
                    if ((left + 1 < right) && nums[left] == nums[left + 1]) {
                        left++;
                        goto left_plus_check;
                    }
                right_sub_check:
                    if((right - 1 > left) && nums[right] == nums[right - 1]) {
                        right--;
                        goto right_sub_check;
                    }
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
            
        }
        check_base:
        if ((i + 1 < numsSize - 2) && nums[i] == nums[i + 1]) {
            i++;
            goto check_base;
        }
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

    printf("i j k | a b c\n");
    printf("--------------\n");
    printf("\n\n");

    p = threeSum(test_case_01, 6, &returnSize, &returnColumnSizes);
    
    printf("return_size: %d\n", returnSize);
    printf_answer(p, returnSize);

    returnSize = 0;

    threeSum(test_case_02, 3, &returnSize, &returnColumnSizes);
    printf("return_size: %d\n", returnSize);
    printf_answer(p, returnSize);
    returnSize = 0;

    threeSum(test_case_03, 3, &returnSize, &returnColumnSizes);
    printf("return_size: %d\n", returnSize);
    printf_answer(p, returnSize);
    returnSize = 0;

    threeSum(test_case_04, 5, &returnSize, &returnColumnSizes);
    printf("return_size: %d\n", returnSize);
    printf_answer(p, returnSize);
    returnSize = 0;

    threeSum(test_case_05, 5, &returnSize, &returnColumnSizes);
    printf("return_size: %d\n", returnSize);
    printf_answer(p, returnSize);
    returnSize = 0;

    threeSum(test_case_06, 3, &returnSize, &returnColumnSizes);
    printf("return_size: %d\n", returnSize);
    printf_answer(p, returnSize);
    returnSize = 0;

    threeSum(test_case_07, 4, &returnSize, &returnColumnSizes);
    printf("return_size: %d\n", returnSize);
    printf_answer(p, returnSize);
    returnSize = 0;
    
    return 0;
}