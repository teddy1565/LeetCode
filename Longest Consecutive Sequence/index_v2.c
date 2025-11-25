#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>

#define TABLE_SIZE 1048576
#define K 200000000
#define A 0.12490286841953102l
#define M 1048576
#define P 20

int hash_func(int k) {
    double KA = k * A;
    double f = fmod(KA, 1);
    int mf = (int)(M * f);
    return mf;
}

int longestConsecutive(int* nums, int numsSize) {
    int hashTable[TABLE_SIZE] = { 0 };

    for (int i = 0; i < numsSize; i++) {
        int index = 0;
        if (nums[i] < 0) {
            index = hash_func(-nums[i]);
        } else {
            index = hash_func(nums[i] + 1000000001);
        }
        hashTable[index] = 1;
    }
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        int index = 0;
        if (nums[i] < 0) {
            index = hash_func(-nums[i]);
        } else {
            index = hash_func(nums[i] + 1000000001);
        }

        if (hashTable[index] == 1) {
            hashTable[index] = 0;
            int pre = nums[i] - 1;
            int next = nums[i] + 1;
            int pre_index = 0;
            int next_index = 0;
            if (pre < 0) {
                pre_index = hash_func(-pre);
            } else {
                pre_index = hash_func(pre + 1000000001);
            }
            
            while (hashTable[pre_index] == 1) {
                hashTable[pre_index] = 0;
                pre--;
                if (pre < 0) {
                    pre_index = hash_func(-pre);
                } else {
                    pre_index = hash_func(pre + 1000000001);
                }
            }
            if (next < 0) {
                next_index = hash_func(-next);
            } else {
                next_index = hash_func(next + 1000000001);
            }
            while (hashTable[next_index] == 1) {
                hashTable[next_index] = 0;
                next++;
                if (next < 0) {
                    next_index = hash_func(-next);
                } else {
                    next_index = hash_func(next + 1000000001);
                }
            }
            int diff = next - pre - 1;
            res = diff > res ? diff : res;
        }
    }
    return res;
}

int main(void) {
    return 0;
}