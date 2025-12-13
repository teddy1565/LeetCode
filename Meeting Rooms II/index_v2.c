#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

int compare_n(const void *a, const void *b) {
    int *x = (int *) a;
    int *y = (int *) b;
    return *x - *y;
}

int minMeetingRooms(int** intervals, int intervalsSize, int* intervalsColSize) {

    int answer = 0;
    int endpos = 0;

    int *starts = (int *) malloc(sizeof(int) * intervalsSize);
    int *ends = (int *) malloc(sizeof(int) * intervalsSize);
    for (int i = 0; i < intervalsSize; i++) {
        starts[i] = intervals[i][0];
        ends[i] = intervals[i][1];
    }
    
    qsort(starts, intervalsSize, sizeof(int), compare_n);
    qsort(ends, intervalsSize, sizeof(int), compare_n);

    for (int i = 0; i < intervalsSize; i++) {
        if (starts[i] < ends[endpos]) answer++;
        else endpos++;
    }
    
    return answer;
}