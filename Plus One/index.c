#include "index.h"


int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *ans = NULL;
    int is_all_nine = 1;
    for (int i = 0; i < digitsSize; i++) {
        if (digits[i] != 9) {
            is_all_nine = 0;
            break;
        }
    }
    if (digitsSize == 1 && digits[0] != 9) {
        is_all_nine = 0;
    }
    if (is_all_nine == 1) {
        (*returnSize) = (digitsSize + 1);
        ans = (int *) malloc(sizeof(int) * (*returnSize));
    } else {
        (*returnSize) = digitsSize;
        ans = (int *) malloc(sizeof(int) * (*returnSize));
    }
    int c = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        ans[i + ((*returnSize) - digitsSize)] = ((digits[i] + c) % 10);
        c = (digits[i] + c) / 10;
    }
    if ((*returnSize) != digitsSize) {
        ans[0] = c;
    }
    return ans;
}

int main(void) {
    return 0;
}