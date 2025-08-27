#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdbool.h>

/**
 * @brief n = a + b + c
 * 
 * n - (a + b + c)  =  0
 * 
 * 
 * @param nums 
 * @param numsSize 
 * @param target 
 * @return int 
 */
int threeSumClosest(int* nums, int numsSize, int target);

// target = 1
/**
 * @brief 
 * 
 */
int test_case_01[4] = { -1, 2, 1, -4 };

// target = 1
int test_case_02[3] = { 0, 0, 0 };

// target = 0
int test_case_03[3] = { 1, 1, -1 };

// target = 1
int test_case_04[9] = { 10, 20, 30, 40, 50, 60, 70, 80, 90 };

// target = -2
int test_case_05[9] = { 4, 0, 5, -5, 3, 3, 0, -4, -5 };

// target = 100
int test_case_06[4] = { 1, 1, 1, 0 };

// target = -14
int test_case_07[10] = { -1000, -5, -5, -5, -5, -5, -5, -1, -1, -1 };

// target = 16
int test_case_08[4] = { 2, 5, 6, 7 };

// target = 15
int test_case_09[6] = { 1, 3, 4, 7, 8, 9};

// target = 78; 9+26+42=77
int test_case_10[13]= { -84, 92, 26, 19, -7, 9, 42, -51, 8, 30, -100, -13, -38 };