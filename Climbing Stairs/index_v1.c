#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// x = 1
// y = 2
// n = 2, { 2 * x + 0 * y, 0 * x + 1 * y }
// n = 3, { 3 * x + 0 * y, 1 * x + 1 * y }
// n = 45, { 45 * x + 0 * y,  }
int climbStairs(int n) {
    int count = 0;
    int x = 1;
    int y = 2;

    for (int i = 0; i <= 45; i++) {
        for (int j = 0; j <= 45; j++) {
            if ((j * x + i * y) == n) {
                count++;
            }
        }
    }
    return count;
}