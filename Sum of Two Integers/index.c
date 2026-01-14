#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int getSum(int a, int b) {
    if (a == 0 && b == 0) {
        return 0;
    }

    while (b != 0) {
        unsigned int carry = (a & b) << 1;
        a = a ^ b;
        b = carry;
    }

    return a;
}

