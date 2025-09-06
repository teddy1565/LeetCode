#include "index.h"

int compare(const void *a, const void *b) {
    return *(int *)a - *(int *)b;
}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    for (int i = m, j = 0; j < n; j++, i++) {
        nums1[i] = nums2[j];
    }

    qsort(nums1, nums1Size, sizeof(int), &compare);
}

int main(void) {
    return 0;
}