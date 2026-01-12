#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int* sortArray(int* nums, int numsSize, int* returnSize){
    int offset = 50000;  // להזיז ערכים שליליים לטווח חיובי
    int count[100001] = {0};

    // ספירת הופעות
    for(int i = 0; i < numsSize; i++){
        count[nums[i] + offset]++;
    }

    // מילוי מחדש של nums לפי הספירה
    int idx = 0;
    for(int i = 0; i <= 100000; i++){
        while(count[i]-- > 0){
            nums[idx++] = i - offset;
        }
    }

    *returnSize = numsSize;
    return nums;
}