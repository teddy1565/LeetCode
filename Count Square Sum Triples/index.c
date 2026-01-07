#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

int countTriples(int n) {
    int count = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int sum = i * i + j * j;
            int root = sqrt(sum);
            if (root <= n) {
                if (root * root == sum) count += 2;
            } else {
                break;
            }
        }
    }
    return count;
}