#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>


#define OFFSET_SIZE sizeof(long long int)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* topKFrequent(int* nums, int numsSize, int k, int* returnSize) {

    if (numsSize == 0) {
        return NULL;
    }
    (*returnSize) = 0;
    
    int **hash_table = (int **) malloc(sizeof(int *) * numsSize);
    double *hash_func = (double *) malloc(sizeof(double) * numsSize);
    memset(hash_func, 0, sizeof(double) * numsSize);

    for (int i = 0; i < numsSize; i++) {
        hash_table[i] = (int *) malloc(sizeof(int) * 1);
    }

    long long int base_addr = (long long int)hash_table[0];
    
    
    int hash_table_index = 0;
    
    // for (int i = 0; i < numsSize; i++) {
        
    //     hash_func[i] = hash_table[hash_table_index] / nums[i];
    // }

// if (nums[i] != 0) {
//             hash_func[i] = (long long int)(hash_table[i]) / nums[i];
//         } else {
//             hash_func[i] = 1;
//         }
    
//     for (int i = 0; i < numsSize; i++) {
//         nums[i]
//     }
    
    return NULL;
}

int main(void) {
    return 0;
}