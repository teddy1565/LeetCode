/**
 * 視為[1] ~ [8]的範圍，也就是8開始到7結尾，兩者取最小值，得出規則，可乘載的水以兩者邊界最小值為準
 *
 * height = [ 1, 8, 6, 2, 5, 4, 8, 3, 7 ]
 * output: 49
 *
 * height = [ 1, 6, 8, 2, 5, 4, 8, 3, 7 ]
 * output: 42
 *
 * 視為[1] ~ [8]的範圍，也就是7開始到7結尾，雖然[2]元素比[1]大，但[1]距離[8]兩者寬度更長，猜測可能存在的規則，高效解答中也許有權重的機制存在
 *
 * height = [ 1, 7, 8, 2, 5, 4, 8, 3, 7 ]
 * output: 49
 */

 /**
  * 思考
  * 1. 求面積題目
  * 2. 本質上，尋找最大面積組合，盡可能高的兩點，以及盡可能寬的距離
  * 3. 從左邊開始分別找到第一大的數字和第二大的數字，再從右邊找出第一大和第二大的數字
  */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int maxArea(int* height, int heightSize) {

    int left_max_index = height[0] > height[1] ? 0: 1;
    int left_sec_max_index = 1 - left_max_index;

    int right_max_index = height[heightSize - 1] > height[heightSize - 2] ? heightSize - 1 : heightSize - 2;
    int right_sec_max_index = height[heightSize - 1] <= height[heightSize - 2] ? heightSize - 1 : heightSize - 2;

    for (int i = 0; i < heightSize; i++) {
        if (height[i] == height[left_max_index]) {
            left_max_index = i;
        } else if (height[i] > height[left_max_index]) {
            left_sec_max_index = left_max_index;
            left_max_index = i;
        } else if (height[i] < height[left_max_index] && height[i] >= height[left_sec_max_index]) {
            left_sec_max_index = i;
        }
    }

    for (int i = heightSize - 1; i > -1; i--) {
        if (height[i] == height[right_max_index]) {
            right_max_index = i;
        } else if (height[i] > height[right_max_index]) {
            right_sec_max_index = right_max_index;
            right_max_index = i;
        } else if (height[i] < height[right_max_index] && height[i] >= height[right_sec_max_index]) {
            right_sec_max_index = i;
        }
    }

    for (int i = 0; i < heightSize; i++) {
        printf("%d ", height[i]);
    }
    printf("\n\n");

    printf("L1: %d\t%d\n", left_max_index, height[left_max_index]);
    printf("L2: %d\t%d\n", left_sec_max_index, height[left_sec_max_index]);
    printf("R1: %d\t%d\n", right_max_index, height[right_max_index]);
    printf("R2: %d\t%d\n", right_sec_max_index, height[right_sec_max_index]);

    return 0;

}

int main(void) {

    int q1[9] = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
    int q2[9] = { 1, 6, 8, 2, 5, 4, 8, 3, 7 };
    int q3[9] = { 1, 7, 8, 2, 5, 4, 8, 3, 7 };

    maxArea(q3, 9);

    return 0;
}