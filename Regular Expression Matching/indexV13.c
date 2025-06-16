#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

bool isMatch(char *s, char *p) {

    printf("==========================================\n\n");
    const int source_str_length = strlen(s);
    const int pattern_str_length = strlen(p);

    char v[20][20] = { -1 };

    for (int i=0; i < pattern_str_length; i++) {
        for (int j=0; j < source_str_length; j++) {
            if (p[i] == s[j]) {
                v[i][j] = 1;
            } else if (p[i] != s[j]) {
                v[i][j] = 0;
            }
        }
    }

    for (int i=0; i < 20; i++) {
        if (i < source_str_length) {
            printf("%c ", s[i]);
        }
    }

    printf("\n--------------------\n");

    for (int i=0; i < 20; i++) {
        for (int j=0; j < 20; j++) {
            printf("%d ", v[i][j]);
        }
        if (i < pattern_str_length) {
            printf("| %c", p[i]);
        }
        printf("\n");
    }

    printf("\n\n");

    return false;
}

int main(void) {
    isMatch("aa", "a*");
    // isMatch("mississippi", "mis*is*p*.");
    // isMatch("mississippi", "mis*is*ip*.");
    return 0;
}