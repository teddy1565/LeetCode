#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// $$\text{Sum}(\text{Sub}_{i, j}) = \text{PrefixSum}[j] - \text{PrefixSum}[i-1]$$
int subarraySum(int* nums, int numsSize, int k) {
    if (numsSize == 0) {
        return 0;
    } else if (numsSize == 1) {
        if (k == nums[0]) {
            return 1;
        }
        return 0;
    }

    int *hash_key_list = (int *) malloc(sizeof(int) * numsSize);
    int *hash_value_list = (int *) malloc(sizeof(int) * numsSize);
    memset(hash_key_list, 0, sizeof(int) * numsSize);
    memset(hash_value_list, 0, sizeof(int) * numsSize);
    int hashIndex = 0;
    int n = 0;
    for (int i = 1; i < numsSize; i++) {
        nums[i] += nums[i - 1];
    }

    hashIndex = 1;
    hash_key_list[0] = 0;

    for (int i = 0; i < numsSize; i++) {
        int m = nums[i] - k;
        printf("m:%d | nums:%d\n", m, nums[i]);
        for (int j = hashIndex-1; j >= 0; j--) {
            if (hash_key_list[j] == m) {
                
                int find = 0;
                int n_key = hashIndex;
                for (int k = hashIndex - 1; k >= 0; k--) {
                    if (hash_key_list[k] == nums[i]) {
                        find = 1;
                        n_key = k;
                        break;
                    }
                }
                if (find == 0) {
                    hash_key_list[n_key] = nums[i];
                    hashIndex += 1;
                }
                hash_value_list[n_key] += 1;
                break;
            }
        }
    }

    for (int i = 0; i < hashIndex; i++) {
        n += hash_value_list[i];
    }

    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }

    printf("\n");

    for (int i = 0; i < hashIndex; i++) {
        printf("%d ", hash_key_list[i]);
    }

    printf("\n");

    for (int i = 0; i < hashIndex; i++) {
        printf("%d ", hash_value_list[i]);
    }

    printf("\n");

    free(hash_key_list);
    free(hash_value_list);

    return n;
}