#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

int getSum(int a, int b) {

    while (b != 0) {
        unsigned int carry = ((unsigned int)(a & b)) << 1;
        a = a ^ b;
        b = carry;
    }

    return a;
}

