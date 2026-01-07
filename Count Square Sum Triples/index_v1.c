#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int countTriples(int n) {
    int m = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (i == j) {
                continue;
            }
            for (int k = n; k > i && k > j; k--) {
                if (i * i + j * j == k * k) {
                    m++;
                }
            }
        }
    }
    return m;
}