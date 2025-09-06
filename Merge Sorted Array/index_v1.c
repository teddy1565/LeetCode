#include "index.h"


void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {

    for (int i = nums1Size - 1, j = m - 1, k = n - 1; i >= 0; i--) {
        if (j < 0) {
            nums1[i] = nums2[k--];
            continue;
        } else if (k < 0) {
            nums1[i] = nums1[j--];
            continue;
        }
        
        int nums1_n = nums1[j];
        int nums2_n = nums2[k];
        if (nums1_n > nums2_n) {
            nums1[i] = nums1_n;
            if (j >= 0) {
                j--;
            } else {
                nums1[i] = nums2_n;
                k--;
            }
        } else {
            nums1[i] = nums2_n;
            k--;
        }
    }
}

int main(void) {
    return 0;
}