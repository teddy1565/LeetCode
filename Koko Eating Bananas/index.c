#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

const static int time_cost(int *piles, int piles_size, int n) {
    long int time_used = 0;
    for (int i = 0; i < piles_size; i++) {
        int plus_one = (piles[i] % n) && 1;
        int time_used_c = piles[i] / n;
        time_used += (long int)(time_used_c + plus_one);
    }
    if (time_used > INT_MAX) {
        return INT_MAX;
    }
    return time_used;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int max = piles[0];
    int min = 1;
    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > max) {
            max = piles[i];
        }
    }

    if (pilesSize == h) {
        return max;
    }

    while (min <= max) {
        int mid = min + (max - min) / 2;
        int n = time_cost(piles, pilesSize, mid);
        if (n <= h) {
            max = mid - 1;
        } else {
            min = mid + 1;
        }
    }
    return min;
}