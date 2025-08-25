#include "index.h"


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

int compare_cb(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}




int stupid[17449];

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
    static int initStatus = 0;
    if (!initStatus) {
        initStatus = 1;
        for (int i = 0; i < 17449; ++i) stupid[i] = 3;
    }

    qsort(nums, numsSize, sizeof(int), &compare_cb);
    
    int **p = (int **) malloc(sizeof(int *) * 17449);


    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        int left = i + 1;
        int right = numsSize - 1;
        while(left < right && left != (right + 1)) {
            int sum = nums[left] + nums[right] + nums[i];
            
            if (sum == 0) {
                int *temp_p = (int *) malloc(sizeof(int) * 3);
                temp_p[0] = nums[i];
                temp_p[1] = nums[left];
                temp_p[2] = nums[right];
                p[(*returnSize)] = temp_p;
                (*returnSize)++;
                
                while ((left + 1 < right) && nums[left] == nums[left + 1]) {
                    left++;
                }
                while ((right - 1 > left) && nums[right] == nums[right - 1]) {
                    right--;
                }
                left++;
                right--;
            } else if (sum > 0) {
                right--;
            } else {
                left++;
            }
        }
    }


    (*returnColumnSizes) = stupid;

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

    threeSum(test_case_08, 4, &returnSize, &returnColumnSizes);
    printf("return_size: %d\n", returnSize);
    printf_answer(p, returnSize);
    returnSize = 0;

    threeSum(test_case_09, 4, &returnSize, &returnColumnSizes);
    printf("return_size: %d\n", returnSize);
    printf_answer(p, returnSize);
    returnSize = 0;
    
    return 0;
}