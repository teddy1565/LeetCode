#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void reverseWords(char* s, int sSize) {
    char* temp_s = (char *) malloc(sizeof(char) * (sSize + 1));
    memset(temp_s, 0, sizeof(char) * (sSize + 1));
    int l = 0;
    for (int i = 0; i < sSize; i++) {
        if (s[i] == ' ') {
            for (int j = sSize - i; l < i; j++, l++) {
                temp_s[j] = s[l];
            }
            temp_s[sSize - i - 1] = s[l++];
        }
    }
    int k = l;
    for (int j = 0; j < (sSize - k); j++, l++) {
        temp_s[j] = s[l];
    }
    
    for (int i = 0; i < sSize; i++) {
        s[i] = temp_s[i];
    }
    free(temp_s);
}