#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


typedef struct {
    int *w_list;
    unsigned int max;
    int w_size;
} Solution;


Solution* solutionCreate(int* w, int wSize) {
    srand( time(NULL) );

    Solution* solution = (Solution *) malloc(sizeof(Solution));
    solution->w_list = w;
    for (int i = 1; i < wSize; i++) {
        w[i] = w[i] + w[i-1];
    }

    solution->max = solution->w_list[wSize-1];
    solution->w_size = wSize;

    return solution;
}

int solutionPickIndex(Solution* obj) {
    int x = ((rand()) % obj->max) + 1;
    int min = 0;
    int max = obj->w_size - 1;

    while (min < max) {
        int middle = min + (max - min) / 2;
        if (obj->w_list[middle] < x) {
            min = middle + 1;
        } else {
            max = middle;
        }
    }

    return min;
}

void solutionFree(Solution* obj) {
    free(obj->w_list);
    free(obj);
}
/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(w, wSize);
 * int param_1 = solutionPickIndex(obj);
 
 * solutionFree(obj);
*/