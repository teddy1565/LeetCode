#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>
#include <stdbool.h>

#define TABLE_SIZE 1048576
// #define K 200000000
#define A 0.12490286841953102l
#define M 1048576
#define P 20
#define OFFSET 1000000002

int hash_func(int k) {
    if (k < 0) {
        k = -k;
    } else {
        k = k + OFFSET;
    }
    double KA = k * A;
    double f = fmod(KA, 1);
    int mf = (int)(M * f);
    return mf;
}

bool containsDuplicate(int* nums, int numsSize) {
    int hashTable[TABLE_SIZE] = { 0 };

    for (int i = 0; i < numsSize; i++) {
        if (hashTable[hash_func(nums[i])] == 1) {
            return true;
        }
        hashTable[hash_func(nums[i])] = 1;
    }
    return false;
}
