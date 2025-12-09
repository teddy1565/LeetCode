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
    int *dp = (int *) malloc(sizeof(int) * envelopesSize);
    for (int i = 0; i < envelopesSize; i++) {
        dp[i] = 1;
    }
    
    for (int i = 0; i < envelopesSize; i++) {
        for (int j = 0; j < i; j++) {
            if (envelopes[i][0] > envelopes[j][0] && envelopes[i][1] > envelopes[j][1]) {
                dp[i] = (dp[i] >= (dp[j] + 1) ? dp[i] : (dp[j] + 1));
            }
        }
        max = max >= dp[i] ? max : dp[i];
    }
    free(dp);
    return max;
}

int main(void) {
    return 0;
}