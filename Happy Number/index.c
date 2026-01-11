#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
bool isHappy(int n) {
    if (n == 1) {
        return true;
    }
    int k = 0;

    until_done:
    while (n != 0) {
        int f = ((n % 10));
        k = k + (f * f);
        n /= 10;
    }
    if (k > 6) {
        n = k;
        k = 0;
        goto until_done;
    }
    if (k == 1) {
        return true;
    }
    return false;
}