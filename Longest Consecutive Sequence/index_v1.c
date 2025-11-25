#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stdint.h>
#include <limits.h>
#define OFFSET 147483647

#define TABLE_SIZE 131072
#define K 200000000
#define A 0.12490286841953102l
#define M 131072
#define P 17

int hash_func(int k) {
    double KA = k * A;
    double f = fmod(KA, 1);
    int mf = (int)(M * f);
    return mf;
}

int longestConsecutive(int* nums, int numsSize) {
    int hashTable[TABLE_SIZE] = { 0 };

    for (int i = 0; i < numsSize; i++) {
        int index = (nums[i]) & INT_MAX;
        if (index < 0) {
            index = nums[i];
        }
        hashTable[index] = 1;
    }
    int res = 0;
    for (int i = 0; i < numsSize; i++) {
        int index = (nums[i]) & INT_MAX;
        if (index < 0) {
            index = nums[i];
        }

        if (hashTable[nums[i]] == 1) {
            hashTable[nums[i]] = 0;
            int pre = nums[i] - 1;
            int next = nums[i] + 1;
            while (hashTable[pre] == 1) {
                hashTable[pre] = 0;
                pre--;
            }
            while (hashTable[next] == 1) {
                hashTable[next] = 0;
                next++;
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