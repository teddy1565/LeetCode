#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* longestCommonPrefix(char** strs, int strsSize) {
    char *s = (char *) malloc(201);
    memset(s, 0, 201);
    int s_index = 0;

    for (int j = 0; j < 200; j++) {
        char c = '\0';
        for (int i = 0; i < strsSize; i++) {
            c = strs[i][j];
            if (c == '\0') {
                break;
            }
            if (s[j] == '\0') {
                s[j] = c;
            } else if (s[j] != c) {
                s[j] = '\0';
                goto leave_loop;
            }
        }
        s[s_index++] = c;
        if (c == '\0') {
            leave_loop:
            break;
        }
    }

    return s;
        
}

int main(void) {
    return 0;
}