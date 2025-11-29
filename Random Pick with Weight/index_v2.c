#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>


typedef struct {
    unsigned int *w_list;
    unsigned int max;
    int w_size;
} Solution;


Solution* solutionCreate(int* w, int wSize) {
    srand( time(NULL) );

    Solution* solution = (Solution *) malloc(sizeof(Solution));
    
    solution->w_list = (unsigned int *) malloc(sizeof(unsigned int) * wSize);

    unsigned int max = w[0];
    solution->w_list[0] = w[0];
    for (int i = 1; i < wSize; i++) {
        solution->w_list[i] = w[i] + solution->w_list[i - 1];
    }

    solution->max = solution->w_list[wSize-1];
    solution->w_size = wSize;

    return solution;
}

int solutionPickIndex(Solution* obj) {
    long int x = (rand()) % obj->max;
    for (int i = 0; i < obj->w_size; i++) {
        if (x - obj->w_list[i] < 0) {
            return i;
        }
    }
    return 0;
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