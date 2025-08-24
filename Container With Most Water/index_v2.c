#include "index.h"

int maxArea(int* height, int heightSize) {
    
    int max_area = 0;

    for (int i = 0, j = heightSize - 1; i < j;) {
        int left_barrier = height[i];
        int right_barrier = height[j];

        int area = 0;
        if (left_barrier >= right_barrier) {
            area = right_barrier * (j - i);
            j--;
        } else if (left_barrier < right_barrier) {
            area = left_barrier * (j - i);
            i++;
        }

        if (area > max_area) {
            max_area = area;
        }
    }

    return max_area;
}

int main(void) {

    int answer = 0;

    answer = maxArea(test_case_01, 9);
    printf("%d\n", answer);
    assert(answer == 49);

    answer = maxArea(test_case_02, 2);
    printf("%d\n", answer);
    assert(answer == 1);

    answer = maxArea(test_case_03, 71050);
    printf("%d\n", answer);
    assert(answer == 705634720);

    return 0;
}