#include <stdio.h>
#include <string.h>
#include <stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* sortArray(int* arr, int n, int* rs) {
    int* ptr;
    int max = arr[0];
    int min = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    int n2 = max-min+1;
    int new_arr[n2];
    for (int i = 0; i < n2; i++) {
        new_arr[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        new_arr[arr[i]-min]++;
    }

    ptr = malloc(n*sizeof(int));

    int k =0;

    for (int i = 0; i < n2; i++) {
        for (int j = 0; j < new_arr[i]; j++) {
            *(ptr+k)=i+min;
            k++;
        }
    }
    
    *rs = n;
    return ptr;
    
}