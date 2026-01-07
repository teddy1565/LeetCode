#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isPalindrome(char* s) {
    int s_length = strlen(s);
    char *s_copy = (char *) malloc(sizeof(char) * (s_length + 1));
    memset(s_copy, 0, sizeof(char) * (s_length + 1));
    int copy_index = 0;
    for (int i = 0; i < s_length; i++) {
        if ((s[i] - '0' < 10 && s[i] - '0' >= 0) || (s[i] - 'a' < 26 && s[i] - 'a' >= 0)) {
            s_copy[copy_index++] = s[i];
        } else if (s[i] - 'A' < 26 && s[i] - 'A' >= 0) {
            s_copy[copy_index++] = s[i] + 32;
        }
    }

    if (copy_index == 0) {
        for (int i = 0; i < s_length; i++) {
            if (s[i] == ' ') {
                s_copy[copy_index++] = s[i];
            }
        }
    }
    for (int i = 0, j = copy_index - 1; i <= j; i++, j--) {
        if (s_copy[i] != s_copy[j]) {
            free(s_copy);
            return false;
        }
    }

    free(s_copy);
    return true;
}