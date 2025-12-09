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
    int max = 0;
    for (int i = 0, n = 1; i < envelopesSize; i++) {
        for (int j = 0, prev_n = 1; j < i; j++) {
            if ((envelopes[i][0] - envelopes[j][0]) > 0 && (envelopes[i][1] - envelopes[j][1]) > 0) {
                n = n >= (prev_n + 1) ? n : (prev_n + 1);
                
            }
        }
        if (n > max) {
            max = n;
        }
        n = 1;
    }
    for (int i = 0; i < envelopesSize; i++) {
        printf("%d %d\n", envelopes[i][0], envelopes[i][1]);
    }
    return max;
}

int main(void) {
    return 0;
}