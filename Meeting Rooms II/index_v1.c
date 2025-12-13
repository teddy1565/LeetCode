#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    int **nodeA = (int **)a;
    int **nodeB = (int **)b;
    
    int w = ((*nodeA)[0] - (*nodeB)[0]);
    int h = ((*nodeB)[1] - (*nodeA)[1]);

    if (w == 0) {
        return h;
    }
    return w;
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize) {
    int answer = 1;
    qsort(intervals, intervalsSize, sizeof(int) * 2, compare);
    int prev_i = 0;
    for (int i = 1; i < intervalsSize; i++) {
        if (intervals[i][0] == intervals[i-1][0]) {
            answer += 1;
        } else {
            for (int j = prev_i; j < i; j++) {
                if (intervals[i][0] < intervals[j][1]) {
                    answer += 1;
                    prev_i = i;
                    break;
                }
            }
        }
    }
    
    return answer;
}

int main(void) {
    return 0;
}