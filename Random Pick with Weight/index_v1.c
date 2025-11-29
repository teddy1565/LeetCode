#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


typedef struct {
    int *w_list;
    int max;
} Solution;


Solution* solutionCreate(int* w, int wSize) {
    srand( time(NULL) );
    
    int total_size = 0;
    for (int i = 0; i < wSize; i++) {
        total_size += w[i];
    }

    Solution* solution = (Solution *) malloc(sizeof(Solution));
    
    solution->w_list = (int *) malloc(sizeof(int) * total_size);
    solution->max = total_size;
    int w_index = 0;
    for (int i = 0; i < wSize; i++) {
        for (int j = 0; j < w[i]; j++) {
            solution->w_list[w_index] = i;
            w_index += 1;
        }
    }
    return solution;
}

int solutionPickIndex(Solution* obj) {
    int x = (rand()) % obj->max;
    return obj->w_list[x];
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