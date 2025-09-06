#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * @brief 
 * 
 * @param nums1 
 * @param nums1Size 
 * @param m 
 * @param nums2 
 * @param nums2Size 
 * @param n 
 * 
 * - nums1.length == m + n
 * - nums2.length == n
 * - 0 <= m, n <= 200
 * - 1 <= m + n <= 200
 * - -109 <= nums1[i], nums2[j] <= 109
 */
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n);