#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(const void *a, const void *b) {
    int **nodeA = (int **)a;
    int **nodeB = (int **)b;
    
    int w = ((*nodeA)[0] - (*nodeB)[0]);
    int h = ((*nodeA)[1] - (*nodeB)[1]);

    if (w == 0) {
        return h;
    }
    return w;
}

int maxEnvelopes(int** envelopes, int envelopesSize, int* envelopesColSize) {
    qsort(envelopes, envelopesSize, sizeof(int) * 2, compare);
    int max = 1;
    for (int i = 1, n = 1, prev_i = 0; i < envelopesSize; i++) {
        if (envelopes[i][0] - envelopes[prev_i][0] > 0 && envelopes[i][1] - envelopes[prev_i][1] > 0) {
            max += 1;
            prev_i = i;
        }
    }
    for (int i = 0; i < envelopesSize; i++) {
        printf("%d %d\n", envelopes[i][0], envelopes[i][1]);
    }
    return max;
}

int main(void) {
    return 0;
}