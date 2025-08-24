#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    char *s = strs[0];

    for (int j = 0; j < strlen(s); j++) {
        for (int i = 1; i < strsSize; i++) {
            if (strs[i][j] != s[j]) {
                s[j] = '\0';
                goto r;
            }
        }
    }

    r:

    return s;
}

int main(void) {
    return 0;
}